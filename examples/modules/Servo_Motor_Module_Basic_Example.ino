#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi / Create IoTBot object

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.lcdWriteMid("--- IoTBot ---", "Servo Motor", "Test Basladi", "Test Started");
    delay(3000); // Başlangıç ekranı / Startup screen
    iotbot.lcdClear();
    iotbot.lcdWriteCR(5, 1, "Angle / Aci");
}

void loop()
{
    iotbot.serialWrite("Angle / Aci: 0");
    iotbot.lcdWriteCR(9, 2, " 0 ");
    iotbot.moduleServoGoAngle(SENSOR_PIN, 0, 5); // Servo 27. pine bağlı / Servo connected to pin 27
    delay(1000);

    iotbot.serialWrite("Angle / Aci: 180");
    iotbot.lcdWriteCR(9, 2, "180");
    iotbot.moduleServoGoAngle(SENSOR_PIN, 180, 10);
    delay(1000);
}