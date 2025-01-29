#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14

void setup()
{
    minibot.begin();             // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();         // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200); // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Smart LED testi başlatıldı / Smart LED test started.");

    // Initialize NeoPixel strip (Pin: GPIO 12, LED Count: 3)
    // NeoPixel şeridini başlat (Pin: GPIO 12, LED Sayısı: 3)
    minibot.moduleSmartLEDPrepare(SENSOR_PIN); //(I025, IO26,IO27,IO32,IO33)

    // Set initial LED colors / Başlangıç renklerini ayarla
    delay(1000);
    minibot.moduleSmartLEDWrite(0, 255, 0, 0); // LED 0: Red / Kırmızı
    delay(1000);
    minibot.moduleSmartLEDWrite(1, 0, 255, 0); // LED 1: Green / Yeşil
    delay(1000);
    minibot.moduleSmartLEDWrite(2, 0, 0, 255); // LED 2: Blue / Mavi
    delay(1000);
}

void loop()
{
    // Run Rainbow Effect / Gökkuşağı Efektini Çalıştır
    minibot.moduleSmartLEDRainbowEffect(50); // Smooth rainbow effect / Yumuşak gökkuşağı efekti
    delay(1000);

    // Run Rainbow Theater Chase Effect / Gökkuşağı Tiyatro Takip Efekti
    minibot.moduleSmartLEDRainbowTheaterChaseEffect(50); // Rainbow theater chase / Gökkuşağı tiyatro ışığı
    delay(1000);

    // Run Red Theater Chase Effect / Kırmızı Tiyatro Takip Efekti
    minibot.moduleSmartLEDTheaterChaseEffect(minibot.getColor(255, 0, 0), 50); // Red theater chase / Kırmızı tiyatro ışığı
    delay(1000);

    // Run Blue Color Wipe Effect / Mavi Renk Temizleme Efekti
    minibot.moduleSmartLEDColorWipeEffect(minibot.getColor(0, 0, 255), 50); // Blue color wipe / Mavi renk temizleme
    delay(1000);
}
