#include <IOTBOT.h>

IOTBOT iotbot;

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Mikrofon Modulu", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    int micValue = iotbot.moduleMicRead(SENSOR_PIN); // Mikrofon sensör verisi / Microphone sensor value
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Mikrofon Degeri:", "", String(micValue).c_str(), "");
    delay(500); // Gecikme / Delay
}
