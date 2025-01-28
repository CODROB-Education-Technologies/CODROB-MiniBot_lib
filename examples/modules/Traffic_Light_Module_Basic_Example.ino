#include <IOTBOT.h>

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Trafik Isigi", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    // Kırmızı ışık / Red light
    iotbot.moduleTraficLightWrite(true, false, false);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Kirmizi Isik", "Red Light", "", "");
    delay(3000);

    // Sarı ışık / Yellow light
    iotbot.moduleTraficLightWrite(false, true, false);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Sari Isik", "Yellow Light", "", "");
    delay(3000);

    // Yeşil ışık / Green light
    iotbot.moduleTraficLightWrite(false, false, true);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Yesil Isik", "Green Light", "", "");
    delay(3000);
}
