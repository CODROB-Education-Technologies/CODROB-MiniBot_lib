#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14

void setup()
{
    minibot.begin();                                                     // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();                                                 // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200);                                         // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Welcome to MiniBot PIR Module Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
    bool motionDetected = minibot.moduleMotionRead(SENSOR_PIN); // PIR sensör verisi / PIR sensor value

    if (motionDetected)
    {
        minibot.serialWrite("Hareket Algılandi! - Motion Detected!");
    }
    else
    {
        minibot.serialWrite("Hareket Yok! - No Motion!");
    }

    delay(500);
}
