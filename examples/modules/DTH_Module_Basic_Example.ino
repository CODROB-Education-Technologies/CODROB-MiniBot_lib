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
    minibot.serialWrite("Welcome to MiniBot Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
    int temperature = minibot.moduleDhtTempRead(SENSOR_PIN); // Sıcaklık değeri okunuyor / Read temperature
    int humidity = minibot.moduleDhtHumRead(SENSOR_PIN);     // Nem değeri okunuyor / Read humidity

    minibot.serialWrite("Sıcaklık / Temperature: ");
    minibot.serialWrite(temperature); // Sıcaklık yazdırılıyor / Print temperature
    minibot.serialWrite("Nem / Humidity: ");
    minibot.serialWrite(humidity); // Nem yazdırılıyor / Print humidity

    delay(2000); // 2 saniye bekle / Wait for 2 seconds
}
