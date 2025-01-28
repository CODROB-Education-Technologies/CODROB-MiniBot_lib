#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Röle testi başlatıldı / Relay test started.");
}

void loop()
{
    iotbot.serialWrite("Röle açık / Relay ON.");
    iotbot.relayWrite(true); // Röle açılıyor / Turn relay ON
    delay(2000);             // 2 saniye bekle / Wait for 2 seconds

    iotbot.serialWrite("Röle kapalı / Relay OFF.");
    iotbot.relayWrite(false); // Röle kapanıyor / Turn relay OFF
    delay(2000);              // 2 saniye bekle / Wait for 2 seconds
}
