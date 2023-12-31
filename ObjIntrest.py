import numpy as np
import time
from adafruit_servokit import ServoKit
print(cv2.__version__)
timeMark=time.time()
dtFIL=0
 
scanRight=True
scanLeft=True
 
def nothing(x):
    pass
 
cv2.namedWindow('TrackBars')
cv2.moveWindow('TrackBars',1320,0)
cv2.createTrackbar('hueLower', 'TrackBars',100,179,nothing)
cv2.createTrackbar('hueUpper', 'TrackBars',116,179,nothing)
cv2.createTrackbar('satLow', 'TrackBars',160,255,nothing)
cv2.createTrackbar('satHigh', 'TrackBars',255,255,nothing)
cv2.createTrackbar('valLow', 'TrackBars',150,255,nothing)
cv2.createTrackbar('valHigh', 'TrackBars',255,255,nothing)
 
cv2.namedWindow('TrackBars2')
cv2.moveWindow('TrackBars2',1100,0)
cv2.createTrackbar('hueLower2', 'TrackBars2',150,179,nothing)
cv2.createTrackbar('hueUpper2', 'TrackBars2',170,179,nothing)
cv2.createTrackbar('satLow2', 'TrackBars2',160,255,nothing)
cv2.createTrackbar('satHigh2', 'TrackBars2',255,255,nothing)
cv2.createTrackbar('valLow2', 'TrackBars2',150,255,nothing)
cv2.createTrackbar('valHigh2', 'TrackBars2',255,255,nothing)
 
 
kit=ServoKit(channels=16)
 
tilt1=90
pan1=90
tilt2=90
pan2=90
 dPan1=1
dPan2=1
dTilt1=10
dTilt2=10
 
kit.servo[0].angle=pan1
kit.servo[1].angle=tilt1
kit.servo[2].angle=pan2
kit.servo[3].angle=tilt2
 
width=720
height=480
flip=2
font=cv2.FONT_HERSHEY_SIMPLEX
camSet1='nvarguscamerasrc sensor-id=0 ee-mode=1 ee-strength=0 tnr-mode=2 tnr-strength=1 wbmode=3 ! video/x-raw(memory:NVMM), width=3264, height=2464, framerate=21/1,format=NV12 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(width)+', height='+str(height)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! videobalance contrast=1.3 brightness=-.2 saturation=1.2 ! appsink drop=True'
camSet2='nvarguscamerasrc sensor-id=1 ee-mode=1 ee-strength=0 tnr-mode=2 tnr-strength=1 wbmode=3 ! video/x-raw(memory:NVMM), width=3264, height=2464, framerate=21/1,format=NV12 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(width)+', height='+str(height)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! videobalance contrast=1.3 brightness=-.2 saturation=1.2 ! appsink drop=True'
 
#camSet='nvarguscamerasrc sensor-id=0 ! video/x-raw(memory:NVMM), width=3264, height=2464, framerate=21/1,format=NV12 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(width)+', height='+str(height)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#camSet ='v4l2src device=/dev/video1 ! video/x-raw,width='+str(width)+',height='+str(height)+',framerate=20/1 ! videoconvert ! appsink'
cam1=cv2.VideoCapture(camSet1)
cam2=cv2.VideoCapture(camSet2)
while True:
    _, frame1 = cam1.read()
    _, frame2 = cam2.read()
 
    hsv1=cv2.cvtColor(frame1,cv2.COLOR_BGR2HSV)
    hsv2=cv2.cvtColor(frame2,cv2.COLOR_BGR2HSV)
 
    hueLow=cv2.getTrackbarPos('hueLower', 'TrackBars')
    hueUp=cv2.getTrackbarPos('hueUpper', 'TrackBars')
 
    Ls=cv2.getTrackbarPos('satLow', 'TrackBars')
    Us=cv2.getTrackbarPos('satHigh', 'TrackBars')
 
    Lv=cv2.getTrackbarPos('valLow', 'TrackBars')
    Uv=cv2.getTrackbarPos('valHigh', 'TrackBars')
 
    l_b=np.array([hueLow,Ls,Lv])
    u_b=np.array([hueUp,Us,Uv])
    hueLow2=cv2.getTrackbarPos('hueLower2', 'TrackBars2')
    hueUp2=cv2.getTrackbarPos('hueUpper2', 'TrackBars2')
 
    Ls2=cv2.getTrackbarPos('satLow2', 'TrackBars2')
    Us2=cv2.getTrackbarPos('satHigh2', 'TrackBars2')
 
    Lv2=cv2.getTrackbarPos('valLow2', 'TrackBars2')
    Uv2=cv2.getTrackbarPos('valHigh2', 'TrackBars2')
 
    l_b2=np.array([hueLow2,Ls2,Lv2])
    u_b2=np.array([hueUp2,Us2,Uv2])
 
    FGmask1=cv2.inRange(hsv1,l_b,u_b)
    FGmask2=cv2.inRange(hsv2,l_b2,u_b2)
 
    cv2.imshow('FGmask1',FGmask1)
    cv2.moveWindow('FGmask1',0,0)
 
    cv2.imshow('FGmask2',FGmask2)
    cv2.moveWindow('FGmask2',350,0)
 
    contours1,_ = cv2.findContours(FGmask1,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    contours1=sorted(contours1,key=lambda x:cv2.contourArea(x),reverse=True)
    for cnt in contours1:
        area=cv2.contourArea(cnt)
        (x,y,w,h)=cv2.boundingRect(cnt)
        if area>=100:
            scanLeft=False
            cv2.rectangle(frame1,(x,y),(x+w,y+h),(0,255,255),3)
            objX=x+w/2
            objY=y+h/2
            errorPan1=objX-width/2
            errorTilt1=objY-height/2
            if abs(errorPan1)>15:
                pan1=pan1+errorPan1/40
            if abs(errorTilt1)>15:
                tilt1=tilt1-errorTilt1/40
            if pan1>180:
                pan1=180
                print('Pan Out of Range')
            if pan1<0:
                pan1=0
                print('Pan Out of Range')
            if tilt1>180:
                tilt1=180
                print('Tilt Out of Range')
            if tilt1<0:
                tilt1=0
            kit.servo[2].angle=pan1
            kit.servo[3].angle=tilt1
            break
    
    contours2,_ = cv2.findContours(FGmask2,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    contours2=sorted(contours2,key=lambda x:cv2.contourArea(x),reverse=True)
    for cnt in contours2:
        area=cv2.contourArea(cnt)
        (x,y,w,h)=cv2.boundingRect(cnt)
        if area>=100:
            scanRight=False
            cv2.rectangle(frame2,(x,y),(x+w,y+h),(0,255,255),3)
            objX=x+w/2
            objY=y+h/2
            errorPan2=objX-width/2
            errorTilt2=objY-height/2
            if abs(errorPan2)>15:
                pan2=pan2+errorPan2/40
            if abs(errorTilt2)>15:
                tilt2=tilt2-errorTilt2/40
            if pan2>180:
                pan2=180
                print('Pan Out of Range')
            if pan2<0:
                pan2=0
                print('Pan Out of Range')
            if tilt2>180:
                tilt2=180
                print('Tilt Out of Range')
            if tilt2<0:
                tilt2=0
            kit.servo[0].angle=pan2
            kit.servo[1].angle=tilt2            
            break
        if scanLeft==True:
        if pan1>=179:
            dPan1=abs(dPan1)*(-1)
        if pan1<=1:
            dPan1=abs(dPan1)
        if pan1>=179 or pan1<=1:
            if tilt1>=170:
                dTilt1=abs(dTilt1)*(-1)
            if tilt1<=10:
                dTilt1=abs(dTilt1)
            tilt1=tilt1+dTilt1
        pan1=pan1+dPan1
        kit.servo[2].angle=pan1
        kit.servo[3].angle=tilt1
    scanLeft=True
 
    if scanRight==True:
        if pan2>=179:
            dPan2=abs(dPan2)*(-1)
        if pan2<=1:
            dPan2=abs(dPan2)
        if pan2>=179 or pan2<=1:
            if tilt2>=170:
                dTilt2=abs(dTilt2)*(-1)
            if tilt2<=10:
                dTilt2=abs(dTilt2)
            tilt2=tilt2+dTilt2
        pan2=pan2+dPan2
        kit.servo[0].angle=pan2
        kit.servo[1].angle=tilt2
    scanRight=True
    
    frame3=np.hstack((frame1,frame2))
    dt=time.time()-timeMark
    timeMark=time.time()
    dtFIL=.9*dtFIL + .1*dt
    fps=1/dtFIL
    cv2.rectangle(frame3,(0,0),(150,40),(0,0,255),-1)
    cv2.putText(frame3,'fps: '+str(round(fps,1)),(0,30),font,1,(0,255,255),2)
 #cv2.imshow('myCam1',frame1)
    #cv2.imshow('myCam2',frame2)
    cv2.imshow('comboCam',frame3)
    cv2.moveWindow('comboCam',0,450)
 
    if cv2.waitKey(1)==ord('q'):
        break
cam1.release()
cam2.release()
cv2.destroyAllWindows()