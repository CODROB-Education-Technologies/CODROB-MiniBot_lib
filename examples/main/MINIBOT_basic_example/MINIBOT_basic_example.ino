#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// MINIBOT nesnesi oluşturuluyor / Create a MINIBOT object
MINIBOT minibot;

void setup()
{
  minibot.begin(); // MINIBOT başlatılıyor / Initialize MINIBOT

  minibot.playIntro(); // Giriş mesajı çalınıyor / Play startup message

  minibot.serialStart(115200); // Seri haberleşmeyi başlat / Start serial communication
  // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
  // Starts serial communication at 115200 baud for computer connection.

  minibot.serialWrite("Welcome to MiniBot Test Firmware!");
  // Hoşgeldiniz mesajını seri porta yazdır / Display welcome message on the serial port
}

void loop()
{
  // 1️⃣ **Buton Durumunu Oku / Read Button State**
  if (minibot.button1Read() == false) // Eğer butona basıldıysa / If button is pressed
  {
    minibot.serialWrite("Button Pressed!");
    // Butona basıldığını seri porta yazdır / Print button pressed message to serial port

    minibot.ledWrite(HIGH);
    // LED'i aç / Turn on LED

    delay(200); // 200 ms bekle / Wait for 200 ms
  }
  else // Eğer buton serbestse / If button is released
  {
    minibot.serialWrite("Button Free");
    // Butonun serbest olduğunu seri porta yazdır / Print button released message to serial port

    minibot.ledWrite(LOW);
    // LED'i kapat / Turn off LED

    delay(200); // 200 ms bekle / Wait for 200 ms
  }
}
