#ifndef MINIBOT_H
#define MINIBOT_H

#if defined(ESP8266)
#include <Arduino.h>
#include <EEPROM.h>

#if defined(USE_SERVO)
#include <Servo.h>
#endif

#if defined(USE_DHT)
#include <DHT.h>
#endif

#if defined(USE_NEOPIXEL)
#include <Adafruit_NeoPixel.h>
#endif

#if defined(USE_IR)
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#endif

#if defined(USE_SERVER)
#ifndef USE_WIFI
#define USE_WIFI
#endif
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#endif

#if defined(USE_FIREBASE)
#ifndef USE_WIFI
#define USE_WIFI
#endif
#include <Firebase_ESP_Client.h>
#include <ArduinoJson.h>
#endif

#if defined(USE_WIFI)
#include <ESP8266WiFi.h>
#endif

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
  void serialWrite(String message);
  void serialWrite(long value);
  void serialWrite(int value);
  void serialWrite(float value);
  void serialWrite(bool value);

  /*********************************** BUTTONS ***********************************/
  bool button1Read();

  /*********************************** LED ***********************************/
  void ledWrite(bool status);

  /*********************************** Servo Motor Sensor ***********************************
   */
#if defined(USE_SERVO)
  void moduleServoGoAngle(int pin, int angle, int acceleration);
#endif

  /*********************************** DHT Sensor ***********************************
   */
#if defined(USE_DHT)
  int moduleDhtTempReadC(int pin);
  int moduleDthFeelingTempC(int pin);
  int moduleDhtTempReadF(int pin);
  int moduleDthFeelingTempF(int pin);
  int moduleDhtHumRead(int pin);
#endif
  /*********************************** Magnetic Sensor ***********************************
   */
  bool moduleMagneticRead(int pin);

  /*********************************** Vibration Sensor ***********************************
   */
  bool moduleVibrationDigitalRead(int pin);

  /*********************************** Ultrasonic Distance Sensor ***********************************
   */
  int moduleUltrasonicDistanceRead();

  /*********************************** Trafic Ligh Sensor ***********************************
   */
  void moduleTraficLightWrite(bool red, bool yellow, bool green);
  void moduleTraficLightWriteRed(bool red);
  void moduleTraficLightWriteYellow(bool yellow);
  void moduleTraficLightWriteGreen(bool green);

  /*********************************** Smart LED Sensor ***********************************
   */
#if defined(USE_NEOPIXEL)
  void extendSmartLEDPrepare(int pin, int numLEDs);
  void extendSmartLEDFill(int startLED, int endLED, int red, int green, int blue);
  void moduleSmartLEDPrepare(int pin);                             // Initialize NeoPixel strip
  void moduleSmartLEDWrite(int led, int red, int green, int blue); // Write RGB values to specific LED
  void moduleSmartLEDRainbowEffect(int wait);                      // Rainbow effect
  void moduleSmartLEDRainbowTheaterChaseEffect(int wait);          // Rainbow theater chase effect
  void moduleSmartLEDTheaterChaseEffect(uint32_t color, int wait); // Theater chase effect
  void moduleSmartLEDColorWipeEffect(uint32_t color, int wait);    // Color wipe effect
  uint32_t getColor(int red, int green, int blue);                 // Helper function for creating colors
#endif
  /*********************************** Motion Sensor ***********************************
   */
  bool moduleMotionRead(int pin);

  /*********************************** IR Sensor ***********************************
   */
  String moduleIRReadHex(int pin);
  int moduleIRReadDecimalx32(int pin);
  int moduleIRReadDecimalx8(int pin);

  /*********************************** Relay Sensor ***********************************
   */
  void moduleRelayWrite(int pin, bool status);

  /*********************************** OTHER PINS ***********************************
   */
  int digitalReadPin(int pin);
  void digitalWritePin(int pin, bool value);

  /*********************************** EEPROM  ***********************************
   */
  void eepromWriteInt(int address, int value);
  int eepromReadInt(int address);

  /*********************************** WiFi  ***********************************
   */
#if defined(USE_WIFI)
  void wifiStartAndConnect(const char *ssid, const char *pass);
  bool wifiConnectionControl();
  String wifiGetMACAddress();
  String wifiGetIPAddress();
#endif

  /*********************************** Server  ***********************************
   */
#if defined(USE_SERVER)
  void serverStart(const char *mode, const char *ssid, const char *password);
  void serverCreateLocalPage(const char *url, const char *WEBPageScript, const char *WEBPageCSS, const char *WEBPageHTML, size_t bufferSize = 4096);
  void serverHandleDNS();
  void serverContinue();
#endif

  /*********************************** Firebase Server  ***********************************
   */
#if defined(USE_FIREBASE)
  // 📡 Firebase Server Functions
  void fbServerSetandStartWithUser(const char *projectURL, const char *secretKey, const char *userMail, const char *mailPass); // projectURL: YOUR_FIREBASE_PROJECT_ID.firebaseio.com / secretKey: YOUR_FIREBASE_DATABASE_SECRET

  // 🔄 Firebase Database Write Functions
  void fbServerSetInt(const char *dataPath, int data);
  void fbServerSetFloat(const char *dataPath, float data);
  void fbServerSetString(const char *dataPath, String data);
  void fbServerSetDouble(const char *dataPath, double data);
  void fbServerSetBool(const char *dataPath, bool data);
  void fbServerSetJSON(const char *dataPath, String data);

  // 📥 Firebase Database Read Functions
  int fbServerGetInt(const char *dataPath);
  float fbServerGetFloat(const char *dataPath);
  String fbServerGetString(const char *dataPath);
  double fbServerGetDouble(const char *dataPath);
  bool fbServerGetBool(const char *dataPath);
  String fbServerGetJSON(const char *dataPath);
#endif
private:
#if defined(USE_SERVO)
  Servo servoModule; // Create a Servo object for controlling the servo motor
  int currentAngle = 0;
#endif

#if defined(USE_DHT)
  void initializeDht(int pin, uint8_t type);
  DHT *dhtSensor; // Pointer to DHT sensor object
#endif

#if defined(USE_NEOPIXEL)
  Adafruit_NeoPixel *pixels; // NeoPixel object pointer
#endif

#if defined(USE_IR)

  void initializeIR(int pin);
  IRrecv *irrecv = nullptr; // Pointer to IR receiver / IR alıcısı için pointer
  decode_results results;   // Stores received IR results / Alınan IR sinyallerini saklar
  int irPin;                // Store the IR receiver pin / IR alıcı pini sakla
  long irRawValue = 0;      // Stores last received IR value / En son alınan IR değerini saklar

#endif

#if defined(USE_SERVER)
  const IPAddress apIP = IPAddress(192, 168, 4, 1); // Sabit IP adresi tanımlanıyor / Define static IP address
  DNSServer dnsServer;                              // DNS sunucusu tanımlanıyor / Define DNS Server
  AsyncWebServer serverCODROB{80};                  // Web server objesi
  AsyncWebSocket *serverCODROBWebSocket;            // Pointer olarak tanımla
#endif

#if defined(USE_FIREBASE)
  FirebaseData firebaseData;     // Data object to handle Firebase communication
  FirebaseAuth firebaseAuth;     // Authentication credentials for user verification
  FirebaseConfig firebaseConfig; // Configuration settings for Firebase
  char uid[128] = "";            // User ID storage
#endif };

#else
#error "MINIBOT sadece ESP8266 için desteklenmektedir."
#endif

#endif
