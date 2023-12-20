import cv2
import face_recognition as FR
font=cv2.FONT_HERSHEY_SIMPLEX
width=640
height=360
cam=cv2.VideoCapture(0,cv2.CAP_DSHOW)
cam.set(cv2.CAP_PROP_FRAME_WIDTH, width)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT,height)
cam.set(cv2.CAP_PROP_FPS, 30)
cam.set(cv2.CAP_PROP_FOURCC,cv2.VideoWriter_fourcc(*'MJPG'))
 
paulFace=FR.load_image_file('C:/Users/Valued Customer/Documents/Python/demoImages/known/Paul McWhorter.jpg')
faceLoc=FR.face_locations(paulFace)[0]
paulFaceEncode=FR.face_encodings(paulFace)[0]
 
gavFace=FR.load_image_file('C:/Users/Valued Customer/Documents/Python/demoImages/known/Gavriella Joy.jpg')
faceLoc=FR.face_locations(gavFace)[0]
gavFaceEncode=FR.face_encodings(gavFace)[0]
 
knownEncodings=[paulFaceEncode,gavFaceEncode]
names=['Paul McWhorter','Gavriella Joy']
 
while True:
    ignore,  unknownFace = cam.read()
 
    unknownFaceRGB=cv2.cvtColor(unknownFace,cv2.COLOR_RGB2BGR)
    faceLocations=FR.face_locations(unknownFaceRGB)
    unknownEncodings=FR.face_encodings(unknownFaceRGB,faceLocations)
 
    for faceLocation,unknownEncoding in zip(faceLocations,unknownEncodings):
        top,right,bottom,left=faceLocation
        print(faceLocation)
        cv2.rectangle(unknownFace,(left,top),(right,bottom),(255,0,0),3)
        name='Unknown Person'
        matches=FR.compare_faces(knownEncodings,unknownEncoding)
        print(matches)
        if True in matches:
            matchIndex=matches.index(True)
            print(matchIndex)
            print(names[matchIndex])
            name=names[matchIndex]
            cv2.putText(unknownFace,name,(left,top),font,.75,(0,0,255),2)
 
    cv2.imshow('My Faces',unknownFace)
    if cv2.waitKey(1) & 0xff ==ord('q'):
        break
cam.release()
cv2.destroyAllWindows()