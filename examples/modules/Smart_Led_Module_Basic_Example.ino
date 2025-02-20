#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// MINIBOT nesnesi oluşturuluyor / Create a MINIBOT object
MINIBOT minibot;

#define SENSOR_PIN IO12 // Akıllı LED'in bağlı olduğu pini seçin / Select the pin connected to the smart LED
// Desteklenen pinler: IO25 - IO26 - IO27 - IO32 - IO33
// Supported pins: IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    minibot.begin(); // MINIBOT başlatılıyor / Initialize MINIBOT

    minibot.playIntro(); // Giriş müziği çalınıyor / Play startup melody
    // MiniBot açıldığında kısa bir melodi çalar.
    // MiniBot plays a short melody when powered on.

    minibot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    minibot.serialWrite("Smart LED testi başlatıldı / Smart LED test started.");
    // Hoşgeldiniz mesajını seri porta yazdır / Display welcome message on the serial port

    // NeoPixel şeridini başlat (Pin: GPIO 12, LED Sayısı: 3)
    // Initialize NeoPixel strip (Pin: GPIO 12, LED Count: 3)
    minibot.moduleSmartLEDPrepare(SENSOR_PIN);

    // LED'leri başlangıç renklerine ayarla / Set initial LED colors
    delay(1000);
    minibot.moduleSmartLEDWrite(0, 255, 0, 0); // LED 0: Kırmızı / Red
    delay(1000);
    minibot.moduleSmartLEDWrite(1, 0, 255, 0); // LED 1: Yeşil / Green
    delay(1000);
    minibot.moduleSmartLEDWrite(2, 0, 0, 255); // LED 2: Mavi / Blue
    delay(1000);
}

void loop()
{
    // 1️⃣ **Gökkuşağı Efekti / Rainbow Effect**
    minibot.moduleSmartLEDRainbowEffect(50);
    // Yumuşak geçişli gökkuşağı efekti uygula / Apply smooth rainbow effect
    delay(1000);

    // 2️⃣ **Gökkuşağı Tiyatro Takip Efekti / Rainbow Theater Chase Effect**
    minibot.moduleSmartLEDRainbowTheaterChaseEffect(50);
    // Gökkuşağı renklerinde tiyatro ışık takip efekti / Rainbow theater chase effect
    delay(1000);

    // 3️⃣ **Kırmızı Tiyatro Takip Efekti / Red Theater Chase Effect**
    minibot.moduleSmartLEDTheaterChaseEffect(minibot.getColor(255, 0, 0), 50);
    // Kırmızı tiyatro ışık takip efekti uygula / Apply red theater chase effect
    delay(1000);

    // 4️⃣ **Mavi Renk Temizleme Efekti / Blue Color Wipe Effect**
    minibot.moduleSmartLEDColorWipeEffect(minibot.getColor(0, 0, 255), 50);
    // Mavi renk temizleme efekti uygula / Apply blue color wipe effect
    delay(1000);
}
