#include <IOTBOT.h>

IOTBOT iotbot;

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Duman Sensoru", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    int smokeLevel = iotbot.moduleSmokeRead(SENSOR_PIN); // Duman sensörü verisi / Smoke sensor value
    iotbot.lcdClear();

    if (smokeLevel > 1400)
    { // Kritik eşik / Critical threshold
        iotbot.lcdWriteMid("Duman Algilandi!", "Smoke Detected!", "", "");
    }
    else
    {
        iotbot.lcdWriteMid("Duman Yok", "No Smoke", "Seviye: ", String(smokeLevel).c_str());
    }

    delay(1000); // 1 saniye gecikme / 1 second delay
}
