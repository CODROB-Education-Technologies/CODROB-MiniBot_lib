#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Smart LED testi başlatıldı / Smart LED test started.");

    iotbot.moduleSmartLEDPrepare(SENSOR_PIN); // Smart LED başlatılıyor / Initialize Smart LED
}

void loop()
{
    iotbot.serialWrite("Kırmızı LED yanıyor / Red LED ON.");
    iotbot.moduleSmartLEDWrite(0, 255, 0, 0); // Kırmızı LED / Red LED
    delay(1000);                              // 1 saniye bekle / Wait for 1 second

    iotbot.serialWrite("Yeşil LED yanıyor / Green LED ON.");
    iotbot.moduleSmartLEDWrite(1, 0, 255, 0); // Yeşil LED / Green LED
    delay(1000);                              // 1 saniye bekle / Wait for 1 second

    iotbot.serialWrite("Mavi LED yanıyor / Blue LED ON.");
    iotbot.moduleSmartLEDWrite(2, 0, 0, 255); // Mavi LED / Blue LED
    delay(1000);                              // 1 saniye bekle / Wait for 1 second
}
