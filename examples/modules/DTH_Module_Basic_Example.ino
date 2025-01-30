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

    minibot.serialWrite("Welcome to MiniBot Test Firmware!");
    // Hoşgeldiniz mesajını seri porta yazdır / Display welcome message on the serial port
}

void loop()
{
    int temperature = minibot.moduleDhtTempRead(SENSOR_PIN);
    // Sıcaklık değeri okunuyor (°C) / Read temperature value (°C)

    int humidity = minibot.moduleDhtHumRead(SENSOR_PIN);
    // Nem değeri okunuyor (%) / Read humidity value (%)

    minibot.serialWrite("Sıcaklık / Temperature: ");
    minibot.serialWrite(temperature);
    // Sıcaklık seri porta yazdırılıyor / Print temperature to serial port

    minibot.serialWrite("Nem / Humidity: ");
    minibot.serialWrite(humidity);
    // Nem seri porta yazdırılıyor / Print humidity to serial port

    delay(2000);
    // Yeni veri okumadan önce 2 saniye bekle / Wait for 2 seconds before reading new data
}
