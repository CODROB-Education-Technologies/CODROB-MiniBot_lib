#ifndef MINIBOT_H
#define MINIBOT_H

#if defined(ESP8266)

#include <Arduino.h>
#include <Servo.h>
#include <DHT.h>
#include <Adafruit_NeoPixel.h>

// PinS
#define B1_BUTTON_PIN 0
#define BLUE_LED 16

#define IO4 4
#define IO5 5
#define IO12 12
#define IO13 13
#define IO14 14

class MINIBOT
{
public:
  MINIBOT();
  void begin();
  void playIntro();

  /*********************************** Serial Port ***********************************
   */
  void serialStart(int baundrate);
  void serialWrite(const char *message);
  void serialWrite(int value);
  void serialWrite(float value);
  void serialWrite(bool value);

  /*********************************** BUTTONS ***********************************/
  int button1Read();

  /*********************************** LED ***********************************/
  void ledWrite(bool status);

  /*********************************** Servo Motor Sensor ***********************************
   */
  void moduleServoGoAngle(int pin, int angle, int acceleration);

  /*********************************** DHT Sensor ***********************************
   */

  int moduleDhtTempRead(int pin);
  int moduleDhtHumRead(int pin);
  int moduleDthFeelingTemp(int pin);

  /*********************************** Magnetic Sensor ***********************************
   */
  int moduleMagneticRead(int pin);

  /*********************************** Vibration Sensor ***********************************
   */
  int moduleVibrationDigitalRead(int pin);

  /*********************************** Ultrasonic Distance Sensor ***********************************
   */
  int moduleUltrasonicDistanceRead();

  /*********************************** Trafic Ligh Sensor ***********************************
   */
  void moduleTraficLightWrite(bool red, bool yellow, bool green);

  /*********************************** Smart LED Sensor ***********************************
   */
  void extendSmartLEDPrepare(int pin, int numLEDs);
  void extendSmartLEDFill(int startLED, int endLED, int red, int green, int blue);

  void moduleSmartLEDPrepare(int pin);                             // Initialize NeoPixel strip
  void moduleSmartLEDWrite(int led, int red, int green, int blue); // Write RGB values to specific LED
  void moduleSmartLEDRainbowEffect(int wait);                      // Rainbow effect
  void moduleSmartLEDRainbowTheaterChaseEffect(int wait);          // Rainbow theater chase effect
  void moduleSmartLEDTheaterChaseEffect(uint32_t color, int wait); // Theater chase effect
  void moduleSmartLEDColorWipeEffect(uint32_t color, int wait);    // Color wipe effect
  uint32_t getColor(int red, int green, int blue);                 // Helper function for creating colors

  /*********************************** Motion Sensor ***********************************
   */
  int moduleMotionRead(int pin);

  /*********************************** IR Sensor ***********************************
   */
  int moduleIRRead(int pin);

  /*********************************** Relay Sensor ***********************************
   */
  void moduleRelayWrite(int pin, bool status);

  /*********************************** OTHER PINS ***********************************
   */
  int digitalReadPin(int pin);
  void digitalWritePin(int pin, int value);

private:
  DHT *dhtSensor; // Pointer to DHT sensor object
  Servo servoModule;
  int currentAngle = 0;
  void initializeDht(int pin, uint8_t type);
  Adafruit_NeoPixel *pixels; // NeoPixel object pointer
};

#else
#error "MINIBOT sadece ESP8266 için desteklenmektedir."
#endif

#endif
