#include <MINIBOT.h>

// MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

void setup()
{
  minibot.begin();
  minibot.playIntro();
}

void loop()
{
  // LCD ekran mesajı
  minibot.lcdWriteMid("MINIBOT Active!", "Press Buttons", "Enjoy the Show!", "");

  // Butonların okunması
  if (minibot.button1Read() == LOW)
  {
    minibot.lcdClear();
    minibot.lcdWriteMid("Button 1", "Pressed!", "", "");
    minibot.buzzerPlayTone(1000, 300);
  }

  if (minibot.button2Read() == LOW)
  {
    minibot.lcdClear();
    minibot.lcdWriteMid("Button 2", "Pressed!", "", "");
    minibot.buzzerPlayTone(800, 300);
  }

  // Servo hareketi örneği
  minibot.servoMove(D2, 90); // D2 pinindeki servo 90 dereceye döner

  // Röle örneği
  minibot.relayWrite(true);
  delay(500);
  minibot.relayWrite(false);
  delay(500);
}
