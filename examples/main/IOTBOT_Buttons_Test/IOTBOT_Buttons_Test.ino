#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Buton testi başlatıldı / Button test started.");

    // LCD başlangıç mesajı / LCD startup message
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Button Test", "--- IoTBot ---", "Test Basladi!", "Starting Test!");
    delay(3000); // 3 saniye bekle / Wait for 3 seconds
}

void loop()
{
    // Buton değerlerini oku / Read button values
    int button1 = iotbot.button1Read(); // B1 butonu / Button 1
    int button2 = iotbot.button2Read(); // B2 butonu / Button 2
    int button3 = iotbot.button3Read(); // B3 butonu / Button 3

    // LCD'ye buton durumlarını yazdır / Display button states on LCD
    iotbot.lcdClear();
    iotbot.lcdWriteCR(0, 0, "Button Test:");
    iotbot.lcdWriteCR(0, 1, "B1: ");
    iotbot.lcdWriteCR(5, 1, button1 == 1 ? "Pressed" : "Released");
    iotbot.lcdWriteCR(0, 2, "B2: ");
    iotbot.lcdWriteCR(5, 2, button2 == 1 ? "Pressed" : "Released");
    iotbot.lcdWriteCR(0, 3, "B3: ");
    iotbot.lcdWriteCR(5, 3, button3 == 1 ? "Pressed" : "Released");

    // Seri porta buton durumlarını yazdır / Print button states to serial
    iotbot.serialWrite("B1: " + String(button1));
    iotbot.serialWrite("B2: " + String(button2));
    iotbot.serialWrite("B3: " + String(button3));

    delay(500); // 500 ms bekle / Wait for 500 ms
}
