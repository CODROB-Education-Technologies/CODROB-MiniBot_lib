#include <IOTBOT.h>

IOTBOT iotbot;

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33
void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("NTC Sicaklik", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    float temp = iotbot.moduleNtcTempRead(SENSOR_PIN); // NTC sıcaklık değeri / NTC temperature value
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Sicaklik:", "Temperature:", String(temp, 1).c_str(), "C");
    delay(1000); // 1 saniyelik gecikme / 1 second delay
}
