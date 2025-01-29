#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

MINIBOT minibot; // MINIBOT nesnesi oluşturuluyor / Create MINIBOT object

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14

void setup()
{
    minibot.begin();             // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();         // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200); // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Smart LED testi başlatıldı / Smart LED test started.");

    minibot.moduleSmartLEDPrepare(SENSOR_PIN); // Smart LED başlatılıyor / Initialize Smart LED
}

void loop()
{
    minibot.serialWrite("Kırmızı LED yanıyor / Red LED ON.");
    minibot.moduleSmartLEDWrite(0, 255, 0, 0); // Kırmızı LED / Red LED
    delay(1000);                               // 1 saniye bekle / Wait for 1 second

    minibot.serialWrite("Yeşil LED yanıyor / Green LED ON.");
    minibot.moduleSmartLEDWrite(1, 0, 255, 0); // Yeşil LED / Green LED
    delay(1000);                               // 1 saniye bekle / Wait for 1 second

    minibot.serialWrite("Mavi LED yanıyor / Blue LED ON.");
    minibot.moduleSmartLEDWrite(2, 0, 0, 255); // Mavi LED / Blue LED
    delay(1000);                               // 1 saniye bekle / Wait for 1 second
}
