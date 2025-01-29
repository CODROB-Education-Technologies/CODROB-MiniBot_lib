#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi / Create IoTBot object

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14

void setup()
{
    minibot.begin();             // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();         // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200); // Start serial communication / Seri haberleşmeyi başlat

    minibot.serialWrite("Welcome to MiniBot IR Reader Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
}
