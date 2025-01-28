#include <IOTBOT.h>

IOTBOT iotbot;

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("PIR Sensor", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    int motionDetected = iotbot.moduleMotionRead(SENSOR_PIN); // PIR sensör verisi / PIR sensor value
    iotbot.lcdClear();

    if (motionDetected)
    {
        iotbot.lcdWriteMid("Hareket Algılandi!", "Motion Detected!", "", "");
    }
    else
    {
        iotbot.lcdWriteMid("Hareket Yok", "No Motion", "", "");
    }

    delay(500);
}
