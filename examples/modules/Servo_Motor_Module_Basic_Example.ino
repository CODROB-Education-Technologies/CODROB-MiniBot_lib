#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14

void setup()
{
    minibot.begin();                                                // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();                                            // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200);                                    // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Welcome to MiniBot Servo Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
    minibot.serialWrite("Angle / Aci: 0");
    minibot.moduleServoGoAngle(SENSOR_PIN, 0, 5); // Servo 27. pine bağlı / Servo connected to pin 27
    delay(1000);

    minibot.serialWrite("Angle / Aci: 180");
    minibot.moduleServoGoAngle(SENSOR_PIN, 180, 10);
    delay(1000);
}
