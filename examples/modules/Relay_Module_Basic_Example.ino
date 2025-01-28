#include <IOTBOT.h>

IOTBOT iotbot;

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Role Modulu", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    // Röleyi aktif hale getir / Activate the relay
    iotbot.moduleRelayWrite(SENSOR_PIN, true);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Role Durumu:", "Relay Status:", "Açık / ON", "");
    delay(3000);

    // Röleyi pasif hale getir / Deactivate the relay
    iotbot.moduleRelayWrite(SENSOR_PIN, false);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Role Durumu:", "Relay Status:", "Kapalı / OFF", "");
    delay(3000);
}
