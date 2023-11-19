#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <semphr.h>

const int ledPin = 13;
const int tempPin = A0;

TaskHandle_t Task1, Task2;
SemaphoreHandle_t tempMutex;

void Task1Code(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        digitalWrite(ledPin, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(ledPin, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void Task2Code(void *pvParameters)
{
    (void)pvParameters;
    float temp;
    while (1)
    {
        xSemaphoreTake(tempMutex, portMAX_DELAY);
        temp = analogRead(tempPin) * 0.48876;
        xSemaphoreGive(tempMutex);

        Serial.print("Temperature: ");
        Serial.println(temp);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    tempMutex = xSemaphoreCreateMutex();

    xTaskCreate(Task1Code, "Task1", 100, NULL, 1, &Task1);
    xTaskCreate(Task2Code, "Task2", 100, NULL, 1, &Task2);

    vTaskStartScheduler();
}

void loop()
{
    // This code will not run as the RTOS scheduler handles the tasks.
}

void vApplicationIdleHook(void)
{
    // This function is called during idle time.
    // You can add low-priority tasks or other operations here.
}
