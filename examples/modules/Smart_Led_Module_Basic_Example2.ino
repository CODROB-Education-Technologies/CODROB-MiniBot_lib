#define USE_NEOPIXEL

#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// MINIBOT nesnesi oluşturuluyor / Create a MINIBOT object
MINIBOT minibot;

#define SENSOR_PIN IO12 // Akıllı LED'in bağlı olduğu pini seçin / Select the pin connected to the Smart LED
// Desteklenen pinler: IO4 - IO5 - IO12 - IO13 - IO14
// Supported pins: IO4 - IO5 - IO12 - IO13 - IO14

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

    minibot.moduleSmartLEDPrepare(SENSOR_PIN);
    // Akıllı LED'leri başlat / Initialize Smart LED
}

void loop()
{
    // 1️⃣ **Kırmızı LED'i Yak / Turn ON Red LED**
    minibot.serialWrite("Kırmızı LED yanıyor / Red LED ON.");
    minibot.moduleSmartLEDWrite(0, 255, 0, 0); // Kırmızı LED / Red LED
    delay(1000);                               // 1 saniye bekle / Wait for 1 second

    // 2️⃣ **Yeşil LED'i Yak / Turn ON Green LED**
    minibot.serialWrite("Yeşil LED yanıyor / Green LED ON.");
    minibot.moduleSmartLEDWrite(1, 0, 255, 0); // Yeşil LED / Green LED
    delay(1000);                               // 1 saniye bekle / Wait for 1 second

    // 3️⃣ **Mavi LED'i Yak / Turn ON Blue LED**
    minibot.serialWrite("Mavi LED yanıyor / Blue LED ON.");
    minibot.moduleSmartLEDWrite(2, 0, 0, 255); // Mavi LED / Blue LED
    delay(1000);                               // 1 saniye bekle / Wait for 1 second
}
