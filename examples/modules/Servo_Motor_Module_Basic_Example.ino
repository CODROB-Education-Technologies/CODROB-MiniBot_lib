#define USE_SERVO

#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// MINIBOT nesnesi oluşturuluyor / Create a MINIBOT object
MINIBOT minibot;

#define SENSOR_PIN IO12 // Sensörün bağlı olduğu pini seçin / Select the sensor pin
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

    minibot.serialWrite("Welcome to MiniBot Servo Test Firmware!");
    // Hoşgeldiniz mesajını seri porta yazdır / Display welcome message on the serial port
}

void loop()
{
    // 1️⃣ **Servo Motoru 0° Konumuna Götür / Move Servo Motor to 0° Position**
    minibot.serialWrite("Angle / Aci: 0"); // Seri porta "Açı: 0" mesajını yaz / Print "Angle: 0" to serial port
    minibot.moduleServoGoAngle(SENSOR_PIN, 0, 5);
    // Servo motoru 0° açısına götür (Hareket hızı: 5 birim)
    // Move the servo motor to 0° position (Movement speed: 5 units)
    delay(1000); // 1 saniye bekle / Wait for 1 second

    // 2️⃣ **Servo Motoru 180° Konumuna Götür / Move Servo Motor to 180° Position**
    minibot.serialWrite("Angle / Aci: 180"); // Seri porta "Açı: 180" mesajını yaz / Print "Angle: 180" to serial port
    minibot.moduleServoGoAngle(SENSOR_PIN, 180, 10);
    // Servo motoru 180° açısına götür (Hareket hızı: 10 birim)
    // Move the servo motor to 180° position (Movement speed: 10 units)
    delay(1000); // 1 saniye bekle / Wait for 1 second
}
