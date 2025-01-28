#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("LDR testi başlatıldı / LDR test started.");
}

void loop()
{
    int ldrValue = iotbot.ldrRead(); // LDR değeri okunuyor / Read LDR value
    iotbot.serialWrite("LDR Değeri / LDR Value: ");
    iotbot.serialWrite(ldrValue); // LDR değeri yazdırılıyor / Print LDR value

    delay(500); // Test için kısa bir gecikme / Short delay for testing
}
