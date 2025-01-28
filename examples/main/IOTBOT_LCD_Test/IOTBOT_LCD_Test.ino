#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("LCD testi başlatıldı / LCD test started.");

    // LCD giriş mesajı / LCD startup message
    iotbot.lcdClear(); // Ekranı temizle / Clear the screen
    iotbot.lcdWriteMid("LCD Test", "--- IoTBot ---", "Test Başladı!", "Starting Test!");
    delay(3000); // 3 saniye bekle / Wait for 3 seconds
}

void loop()
{
    // Ekranı temizle ve temel mesajlar yazdır / Clear the screen and write basic messages
    iotbot.lcdClear();
    iotbot.lcdWriteCR(0, 0, "IoTBot LCD Test");
    iotbot.lcdWriteCR(0, 1, "Row 1 / Satır 1");
    iotbot.lcdWriteCR(0, 2, "Row 2 / Satır 2");
    iotbot.lcdWriteCR(0, 3, "Row 3 / Satır 3");
    delay(2000); // 2 saniye bekle / Wait for 2 seconds

    // LCD'de hareketli yazı testi / Scrolling text test on LCD
    iotbot.lcdClear();
    for (int i = 0; i < 20; i++)
    {
        iotbot.lcdWriteCR(i, 1, "-> IoTBot <-"); // Yazıyı sağa kaydır / Shift text to the right
        delay(200);                              // 200 ms bekle / Wait for 200 ms
        iotbot.lcdClear();                       // Temizle / Clear
    }

    // Sayı ve değer yazma testi / Number and value test
    iotbot.lcdClear();
    iotbot.lcdWriteCR(0, 0, "Sayilar Test / Num:");
    for (int i = 0; i <= 10; i++)
    {
        iotbot.lcdWriteCR(12, 1, i); // Sayıları yazdır / Print numbers
        delay(500);                  // 500 ms bekle / Wait for 500 ms
    }

    // LCD'de sabit metin / Static text test
    iotbot.lcdClear();
    iotbot.lcdWriteMid("IoTBot Testi", "LCD Modulu", "Basarili!", "Successful!");
    delay(5000); // 5 saniye bekle / Wait for 5 seconds
}
