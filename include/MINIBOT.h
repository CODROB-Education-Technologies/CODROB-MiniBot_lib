#ifndef MINIBOT_H
#define MINIBOT_H

#if defined(ESP8266)

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <Servo.h>

// Pin Tanımlamaları
#define JOYSTICK_BUTTON_PIN D3
#define ENCODER_A_PIN D5
#define ENCODER_B_PIN D6
#define ENCODER_BUTTON_PIN D4
#define B1_BUTTON_PIN D7
#define B2_BUTTON_PIN D8
#define BUZZER_PIN D2
#define RELAY_PIN D1
#define LCD_ADRESS 0x27

class MINIBOT
{
public:
  MINIBOT();
  void begin();
  void playIntro();

  /*********************************** BUZZER ***********************************/
  void buzzerPlayTone(int frequency, int duration);
  void buzzerSoundIntro();

  /*********************************** LCD ***********************************/
  void lcdWriteMid(const char *line1, const char *line2, const char *line3, const char *line4);
  void lcdWrite(const char *text);
  void lcdClear();

  /*********************************** BUTTONS ***********************************/
  int button1Read();
  int button2Read();
  int joystickButtonRead();

  /*********************************** RELAY ***********************************/
  void relayWrite(bool status);

  /*********************************** SERVO ***********************************/
  void servoMove(int pin, int angle);

  /*********************************** ENCODER ***********************************/
  int encoderRead();
  int encoderButtonRead();

private:
  LiquidCrystal_I2C lcd;
  Servo servoMotor;
  int encoderCount;
  int lastStateA;
};

#else
#error "MINIBOT sadece ESP8266 için desteklenmektedir."
#endif

#endif
