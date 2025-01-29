#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

void setup()
{
  minibot.begin();             // Initialize MINIBOT / MINIBOT başlatılıyor
  minibot.playIntro();         // Play startup melody / Giriş müziği çalınıyor
  minibot.serialStart(115200); // Start serial communication / Seri haberleşmeyi başlat

  minibot.serialWrite("Welcome to MiniBot Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
  // Read button state / Buton durumunu oku
  if (minibot.button1Read() == LOW)
  {
    minibot.serialWrite("Button Pressed!"); // Print button pressed message / Butona basıldığını yazdır

    minibot.ledWrite(HIGH); // Turn on LED / LED'i aç
    delay(200);
  }
  else
  {
    minibot.serialWrite("Button Free"); // Print button released message / Butonun serbest olduğunu yazdır

    minibot.ledWrite(LOW); // Turn off LED / LED'i kapat
    delay(200);
  }
}
