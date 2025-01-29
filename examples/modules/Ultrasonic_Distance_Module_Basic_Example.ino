#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14
void setup()
{
    minibot.begin();                                                              // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();                                                          // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200);                                                  // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Welcome to MiniBot Ultrasonic Distance Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
    int distance = minibot.moduleUltrasonicDistanceRead(); // Mesafe ölçülüyor / Measure distance

    minibot.serialWrite("Mesafe / Distance: ");
    minibot.serialWrite(distance); // Mesafe yazdırılıyor / Print distance

    delay(1000); // 1 saniye bekle / Wait for 1 second
}
