#include "MINIBOT.h"

MINIBOT::MINIBOT()
    : lcd(LCD_ADRESS, 20, 4), encoderCount(0), lastStateA(LOW) {}

void MINIBOT::begin()
{
  pinMode(JOYSTICK_BUTTON_PIN, INPUT_PULLUP);
  pinMode(ENCODER_A_PIN, INPUT);
  pinMode(ENCODER_B_PIN, INPUT);
  pinMode(ENCODER_BUTTON_PIN, INPUT_PULLUP);
  pinMode(B1_BUTTON_PIN, INPUT_PULLUP);
  pinMode(B2_BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void MINIBOT::playIntro()
{
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("--- MINIBOT ---");
  lcd.setCursor(4, 3);
  lcd.print("Powered by ESP8266");
  delay(2000);
  buzzerSoundIntro();
}

void MINIBOT::buzzerPlayTone(int frequency, int duration)
{
  tone(BUZZER_PIN, frequency, duration);
  delay(duration);
  noTone(BUZZER_PIN);
}

void MINIBOT::buzzerSoundIntro()
{
  buzzerPlayTone(500, 200);
  delay(100);
  buzzerPlayTone(700, 200);
  delay(100);
  buzzerPlayTone(1000, 300);
}

void MINIBOT::lcdWriteMid(const char *line1, const char *line2, const char *line3, const char *line4)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  lcd.setCursor(0, 2);
  lcd.print(line3);
  lcd.setCursor(0, 3);
  lcd.print(line4);
}

void MINIBOT::lcdWrite(const char *text)
{
  lcd.print(text);
}

void MINIBOT::lcdClear()
{
  lcd.clear();
}

int MINIBOT::button1Read()
{
  return digitalRead(B1_BUTTON_PIN);
}

int MINIBOT::button2Read()
{
  return digitalRead(B2_BUTTON_PIN);
}

int MINIBOT::joystickButtonRead()
{
  return digitalRead(JOYSTICK_BUTTON_PIN);
}

void MINIBOT::relayWrite(bool status)
{
  digitalWrite(RELAY_PIN, status ? HIGH : LOW);
}

void MINIBOT::servoMove(int pin, int angle)
{
  servoMotor.attach(pin);
  angle = constrain(angle, 0, 180);
  servoMotor.write(angle);
  delay(500);
  servoMotor.detach();
}

int MINIBOT::encoderRead()
{
  int currentStateA = digitalRead(ENCODER_A_PIN);
  if (currentStateA != lastStateA)
  {
    if (digitalRead(ENCODER_B_PIN) != currentStateA)
    {
      encoderCount++;
    }
    else
    {
      encoderCount--;
    }
  }
  lastStateA = currentStateA;
  return encoderCount;
}

int MINIBOT::encoderButtonRead()
{
  return digitalRead(ENCODER_BUTTON_PIN);
}
