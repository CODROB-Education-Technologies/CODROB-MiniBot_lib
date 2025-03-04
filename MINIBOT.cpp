#include <MINIBOT_Config.h>
#include "MINIBOT.h"

MINIBOT::MINIBOT()
{
#if defined(USE_SERVER)
  serverCODROBWebSocket = new AsyncWebSocket("/serverCODROBWebSocket");
#endif
}

void MINIBOT::begin()
{
  pinMode(B1_BUTTON_PIN, INPUT_PULLUP);
  pinMode(BLUE_LED, OUTPUT);
}

void MINIBOT::playIntro()
{
  digitalWrite(BLUE_LED, HIGH);
  delay(100);
  digitalWrite(BLUE_LED, LOW);
  delay(100);
  digitalWrite(BLUE_LED, HIGH);
  delay(100);
  digitalWrite(BLUE_LED, LOW);
  delay(100);
  digitalWrite(BLUE_LED, HIGH);
  delay(100);
  digitalWrite(BLUE_LED, LOW);
  delay(100);
}

/*********************************** Serial Port ***********************************
 */
void MINIBOT::serialStart(int baudrate)
{
  Serial.begin(baudrate);
}

void MINIBOT::serialWrite(const char *message) // Overloaded function for const char* / `const char*` için fonksiyon
{
  Serial.println(message);
}

void MINIBOT::serialWrite(String message) // Overloaded function for String / `String` için özel fonksiyon
{
  Serial.println(message.c_str()); // Convert String to const char*
}

void MINIBOT::serialWrite(long value) // Overloaded function for long / `long` için özel fonksiyon
{
  Serial.println(String(value).c_str());
}

void MINIBOT::serialWrite(int value) // Overloaded function for int / `int` için fonksiyon
{
  Serial.println(String(value).c_str());
}

void MINIBOT::serialWrite(float value) // Overloaded function for float / `float` için fonksiyon
{
  Serial.println(String(value).c_str());
}

void MINIBOT::serialWrite(bool value) // Overloaded function for bool / `bool` için fonksiyon
{
  Serial.println(value ? "true" : "false");
}

/*********************************** BUTTONS ***********************************
 */
bool MINIBOT::button1Read()
{
  return digitalRead(B1_BUTTON_PIN);
}

/*********************************** LED ***********************************
 */
void MINIBOT::ledWrite(bool status)
{
  return digitalWrite(BLUE_LED, status);
}

/*********************************** Servo Angle Control ***********************************
 * Moves a servo to the specified angle with optional acceleration control.
 * pin: The GPIO pin connected to the servo signal.
 * angle: The target angle for the servo (0° to 180°).
 * acceleration: The delay (in milliseconds) between incremental movements.
 */
#ifdef USE_SERVO // Eğer main.cpp içinde tanımlandıysa, burada aktif olur

void MINIBOT::moduleServoGoAngle(int pin, int angle, int acceleration)
{
  // Ensure acceleration is valid
  acceleration = max(acceleration, 1); // Minimum 1 ms gecikme

  // Attach the servo to the specified pin if not already attached
  if (!servoModule.attached())
  {
    servoModule.attach(pin, 500, 2500); // Sadece bağlı değilse ata
  }

  // Ensure angle is within valid bounds (0 to 180 degrees)
  angle = constrain(angle, 0, 180);

  // Get the current position of the servo
  // int currentAngle = servoModule.read(); // Read the current angle (0° to 180°)

  // Determine movement direction (1 for increasing, -1 for decreasing)
  int step = (angle > currentAngle) ? 1 : -1;

  // Gradually move the servo to the target angle with acceleration
  for (int pos = currentAngle; pos != angle; pos += step)
  {
    servoModule.write(pos); // Move servo to the next position
    delay(acceleration);    // Delay for acceleration control
  }
  currentAngle = angle; // Read the current angle (0° to 180°)

  // Ensure the final angle is set correctly
  servoModule.write(angle);
}
#endif

/*********************************** DHT Sensor Initialization ***********************************
 * Configures the DHT sensor.
 * This is automatically initialized when reading temperature or humidity.
 */
#if defined(USE_DHT)
void MINIBOT::initializeDht(int pin, uint8_t type)
{
  if (!dhtSensor)
  {
    dhtSensor = new DHT(pin, type); // Create a new DHT object
    dhtSensor->begin();             // Initialize the sensor
  }
}

int MINIBOT::moduleDhtTempReadC(int pin) // Read Temperature
{
  initializeDht(pin, DHT11); // Ensure DHT11 is initialized
  float temp = dhtSensor->readTemperature();

  if (isnan(temp)) // Check if reading failed
    return -999;

  return static_cast<int>(temp);
}

int MINIBOT::moduleDthFeelingTempC(int pin) // Calculate Heat Index (Feeling Temperature)
{
  initializeDht(pin, DHT11); // Ensure DHT11 is initialized

  float temp = dhtSensor->readTemperature();
  float hum = dhtSensor->readHumidity();

  if (isnan(temp) || isnan(hum)) // Check if readings failed
    return -999;

  float heatIndex = dhtSensor->computeHeatIndex(temp, hum, false); // Calculate heat index in Celsius
  return static_cast<int>(heatIndex);
}

int MINIBOT::moduleDhtTempReadF(int pin) // Read Temperature in Fahrenheit
{
  initializeDht(pin, DHT11);                     // Ensure DHT11 is initialized
  float temp = dhtSensor->readTemperature(true); // **Fahrenheit sıcaklık okuma**

  if (isnan(temp)) // Check if reading failed
    return -999;

  return static_cast<int>(temp);
}

int MINIBOT::moduleDthFeelingTempF(int pin) // Calculate Heat Index (Feeling Temperature in Fahrenheit)
{
  initializeDht(pin, DHT11); // Ensure DHT11 is initialized

  float temp = dhtSensor->readTemperature(true); // **Fahrenheit sıcaklık okuma**
  float hum = dhtSensor->readHumidity();         // **Nem okuma**

  if (isnan(temp) || isnan(hum)) // Check if readings failed
    return -999;

  float heatIndex = dhtSensor->computeHeatIndex(temp, hum, true); // **Fahrenheit olarak hissedilen sıcaklık hesapla**
  return static_cast<int>(heatIndex);
}

int MINIBOT::moduleDhtHumRead(int pin) // Read Humidity
{
  initializeDht(pin, DHT11); // Ensure DHT11 is initialized
  float hum = dhtSensor->readHumidity();

  if (isnan(hum)) // Check if reading failed
    return -999;

  return static_cast<int>(hum);
}
#endif

/*********************************** Magnetic Sensor ***********************************
 */
bool MINIBOT::moduleMagneticRead(int pin)
{
  pinMode(pin, INPUT);
  return !digitalRead(pin);
}

/*********************************** Vibration Sensor ***********************************
 */
bool MINIBOT::moduleVibrationDigitalRead(int pin)
{
  pinMode(pin, INPUT);
  return digitalRead(pin);
}

/*********************************** Ultrasonic Distance Sensor ***********************************
 * Reads distance from the ultrasonic sensor using echo and trigger pins.
 * Automatically adjusts for ESP32 and ESP8266 platforms.
 * Returns 0 if the distance exceeds the maximum measurable range (400 cm).
 */
int MINIBOT::moduleUltrasonicDistanceRead()
{
#if defined(ESP8266)
  const int TRIG_PIN = IO12;
  const int ECHO_PIN = IO13;
#else
#error "Unsupported platform! Only ESP8266 are supported."
#endif

  // Maximum measurable distance for HC-SR04 (in centimeters)
  const int MAX_DISTANCE = 400;

  // Configure pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Send a 10-microsecond pulse on the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(ECHO_PIN, HIGH, MAX_DISTANCE * 58); // Timeout for MAX_DISTANCE

  // If no echo is received, return 0 (out of range)
  if (duration == 0)
  {
    return 0; // Out of range or no object detected
  }

  // Calculate the distance in centimeters
  int distance = duration * 0.034 / 2; // Sound speed: 0.034 cm/µs, divide by 2 for round trip

  // If the calculated distance exceeds the maximum range, return 0
  if (distance > MAX_DISTANCE)
  {
    return 000;
  }

  return distance; // Return the measured distance
}

/*********************************** Trafic Ligh Sensor ***********************************
 */
void MINIBOT::moduleTraficLightWrite(bool red, bool yellow, bool green)
{
#if defined(ESP8266)
  const int RED_PIN = IO13;
  const int YELLOW_PIN = IO5;
  const int GREEN_PIN = IO4;
#else
#error "Unsupported platform! Only ESP8266 are supported."
#endif

  // Configure pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  if (red)
  {
    digitalWrite(RED_PIN, HIGH);
  }
  else
  {
    digitalWrite(RED_PIN, LOW);
  }
  if (yellow)
  {
    digitalWrite(YELLOW_PIN, HIGH);
  }
  else
  {
    digitalWrite(YELLOW_PIN, LOW);
  }
  if (green)
  {
    digitalWrite(GREEN_PIN, HIGH);
  }
  else
  {
    digitalWrite(GREEN_PIN, LOW);
  }
}

void MINIBOT::moduleTraficLightWriteRed(bool red)
{
#if defined(ESP8266)
  const int RED_PIN = IO13;
#else
#error "Unsupported platform! Only ESP8266 are supported."
#endif

  // Configure pins
  pinMode(RED_PIN, OUTPUT);

  if (red)
  {
    digitalWrite(RED_PIN, HIGH);
  }
  else
  {
    digitalWrite(RED_PIN, LOW);
  }
}

void MINIBOT::moduleTraficLightWriteYellow(bool yellow)
{
#if defined(ESP8266)
  const int YELLOW_PIN = IO5;
#else
#error "Unsupported platform! Only ESP8266 are supported."
#endif

  // Configure pins
  pinMode(YELLOW_PIN, OUTPUT);

  if (yellow)
  {
    digitalWrite(YELLOW_PIN, HIGH);
  }
  else
  {
    digitalWrite(YELLOW_PIN, LOW);
  }
}

void MINIBOT::moduleTraficLightWriteGreen(bool green)
{
#if defined(ESP8266)
  const int GREEN_PIN = IO4;
#else
#error "Unsupported platform! Only ESP8266 are supported."
#endif

  // Configure pins

  pinMode(GREEN_PIN, OUTPUT);

  if (green)
  {
    digitalWrite(GREEN_PIN, HIGH);
  }
  else
  {
    digitalWrite(GREEN_PIN, LOW);
  }
}

/*********************************** Smart LED Sensor ***********************************
 */
#if defined(USE_NEOPIXEL)
void MINIBOT::extendSmartLEDPrepare(int pin, int numLEDs)
{
  // Create a new Adafruit_NeoPixel object dynamically
  pixels = new Adafruit_NeoPixel(numLEDs, pin, NEO_GRB + NEO_KHZ800);
  pixels->begin(); // Initialize the NeoPixel strip
  pixels->show();  // Turn off all LEDs initially
}

void MINIBOT::extendSmartLEDFill(int startLED, int endLED, int red, int green, int blue)
{
  if (pixels)
  {
    // Set the color for a range of LEDs
    for (int i = startLED; i <= endLED; i++)
    {
      pixels->setPixelColor(i, pixels->Color(red, green, blue));
    }
    pixels->show(); // Update the LEDs
  }
}

void MINIBOT::moduleSmartLEDPrepare(int pin)
{
  pixels = new Adafruit_NeoPixel(3, pin, NEO_GRB + NEO_KHZ800);
  pixels->begin();
  pixels->show(); // Clear all LEDs
}

void MINIBOT::moduleSmartLEDWrite(int led, int red, int green, int blue)
{
  if (pixels)
  {
    pixels->setPixelColor(led, pixels->Color(red, green, blue));
    pixels->show();
  }
}

uint32_t MINIBOT::getColor(int red, int green, int blue)
{
  return pixels->Color(red, green, blue);
}

void MINIBOT::moduleSmartLEDRainbowEffect(int wait)
{
  if (pixels)
  {
    for (long firstPixelHue = 0; firstPixelHue < 3 * 65536; firstPixelHue += 256)
    {
      for (int i = 0; i < pixels->numPixels(); i++)
      {
        int pixelHue = firstPixelHue + (i * 65536L / pixels->numPixels());
        pixels->setPixelColor(i, pixels->gamma32(pixels->ColorHSV(pixelHue)));
      }
      pixels->show();
      delay(wait);
    }
  }
}

void MINIBOT::moduleSmartLEDRainbowTheaterChaseEffect(int wait)
{
  if (pixels)
  {
    int firstPixelHue = 0;
    for (int a = 0; a < 30; a++)
    {
      for (int b = 0; b < 3; b++)
      {
        pixels->clear();
        for (int c = b; c < pixels->numPixels(); c += 3)
        {
          int hue = firstPixelHue + c * 65536L / pixels->numPixels();
          uint32_t color = pixels->gamma32(pixels->ColorHSV(hue));
          pixels->setPixelColor(c, color);
        }
        pixels->show();
        delay(wait);
        firstPixelHue += 65536 / 90;
      }
    }
  }
}

void MINIBOT::moduleSmartLEDTheaterChaseEffect(uint32_t color, int wait)
{
  if (pixels)
  {
    for (int a = 0; a < 10; a++)
    {
      for (int b = 0; b < 3; b++)
      {
        pixels->clear();
        for (int c = b; c < pixels->numPixels(); c += 3)
        {
          pixels->setPixelColor(c, color);
        }
        pixels->show();
        delay(wait);
      }
    }
  }
}

void MINIBOT::moduleSmartLEDColorWipeEffect(uint32_t color, int wait)
{
  if (pixels)
  {
    for (int i = 0; i < pixels->numPixels(); i++)
    {
      pixels->setPixelColor(i, color);
      pixels->show();
      delay(wait);
    }
  }
}
#endif

/*********************************** Motion Sensor ***********************************
 */
bool MINIBOT::moduleMotionRead(int pin)
{
  pinMode(pin, INPUT);
  return digitalRead(pin);
}

/*********************************** IR Sensor ***********************************
 */
#if defined(USE_IR)

// Initialize the IR module / IR modülünü başlat
void MINIBOT::initializeIR(int pin)
{
  if (!irrecv || irPin != pin)
  {                                           // Eğer IR alıcı yoksa veya pin değişmişse baştan başlat
    irPin = pin;                              // Store the IR receiver pin / IR alıcı pini sakla
    delete irrecv;                            // Önceki nesneyi temizle
    irrecv = new IRrecv(pin, 1024, 50, true); // Create a new IRrecv instance / Yeni bir IRrecv nesnesi oluştur
    irrecv->enableIRIn();                     // Start the IR receiver / IR alıcıyı başlat
  }
}

// Read IR signal in hexadecimal format / IR sinyalini HEX formatında oku
String MINIBOT::moduleIRReadHex(int pin)
{
  initializeIR(pin); // Ensure IR is initialized / IR'nin başlatıldığından emin ol
  if (irrecv->decode(&results))
  {
    String hexCode = "0x" + String(results.value, HEX); // Convert to HEX / HEX formatına çevir
    irrecv->resume();                                   // Continue receiving new data / Yeni veri almak için devam et
    return hexCode;
  }
  return "0"; // No signal received / Sinyal yoksa 0 döndür
}

// Read IR signal as a full 32-bit decimal value / IR sinyalini tam 32-bit ondalık formatta oku
int MINIBOT::moduleIRReadDecimalx32(int pin)
{
  initializeIR(pin); // Ensure IR is initialized / IR'nin başlatıldığından emin ol
  if (irrecv->decode(&results))
  {
    int decimalCode = results.value; // Return the full 32-bit value / Tam 32-bit değeri döndür
    irrecv->resume();                // Continue receiving new data / Yeni veri almak için devam et
    return decimalCode;
  }
  return 0; // No signal received / Sinyal yoksa 0 döndür
}

// Read IR signal as only the last 8 bits (for smaller values) / IR sinyalini sadece son 8 bit olarak oku (küçük değerler için)
int MINIBOT::moduleIRReadDecimalx8(int pin)
{
  initializeIR(pin); // Ensure IR is initialized / IR'nin başlatıldığından emin ol
  if (irrecv->decode(&results))
  {
    int smallCode = results.value & 0xFF; // Extract only the last 8 bits / Sadece son 8 biti al
    irrecv->resume();                     // Continue receiving new data / Yeni veri almak için devam et
    return smallCode;
  }
  return 0; // No signal received / Sinyal yoksa 0 döndür
}
#endif

/*********************************** Relay Sensor ***********************************
 */
void MINIBOT::moduleRelayWrite(int pin, bool status)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, status);
}

/*********************************** OTHER PINS ***********************************
 */

int MINIBOT::digitalReadPin(int pin)
{
  pinMode(pin, INPUT);
  return digitalRead(pin);
}

void MINIBOT::digitalWritePin(int pin, bool value)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, value);
}

/*********************************** EEPROM  ***********************************
 */
void MINIBOT::eepromWriteInt(int address, int value) // EEPROM'a güvenli bir şekilde int türünde veri yazmak için fonksiyon
{
  byte highByte = highByte(value); // int'in yüksek baytını al
  byte lowByte = lowByte(value);   // int'in düşük baytını al

  EEPROM.write(address, highByte);    // İlk baytı EEPROM'a yaz
  EEPROM.write(address + 1, lowByte); // İkinci baytı EEPROM'a yaz
  EEPROM.commit();                    // Değişiklikleri kaydetmek için commit işlemi yapılmalıdır
}

int MINIBOT::eepromReadInt(int address) // EEPROM'dan int türünde veri okumak için fonksiyon
{
  byte highByte = EEPROM.read(address);    // İlk baytı oku
  byte lowByte = EEPROM.read(address + 1); // İkinci baytı oku
  return word(highByte, lowByte);          // Yüksek ve düşük baytları birleştirerek int değeri oluştur
}

/*********************************** WiFi ***********************************/
#if defined(USE_WIFI)

void MINIBOT::wifiStartAndConnect(const char *ssid, const char *pass)
{
  Serial.printf("[WiFi]: Connection Starting!\r\n[WiFi]: SSID: %s\r\n[WiFi]: Pass: %s\r\n", ssid, pass);

  WiFi.begin(ssid, pass);
  int count = 0;
  while (count < 30)
  {
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.printf("\n[WiFi]: Connected!\r\n[WiFi]: Local IP: %s\r\n", WiFi.localIP().toString().c_str());
      Serial.printf("[WiFi]: MAC Address: %s\r\n", WiFi.macAddress().c_str());
      return;
    }
    Serial.print(".");
    delay(500);
    count++;
  }
  Serial.println("[WiFi]: Connection Timeout!");
}

bool MINIBOT::wifiConnectionControl()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("[WiFi]: Connection OK!");
    return true;
  }
  else
  {
    Serial.println("[WiFi]: Connection ERROR!");
    return false;
  }
}

String MINIBOT::wifiGetMACAddress()
{
  return WiFi.macAddress();
}

String MINIBOT::wifiGetIPAddress()
{
  return WiFi.localIP().toString();
}
#endif

/*********************************** Server ***********************************/
#if defined(USE_SERVER)
void MINIBOT::serverStart(const char *mode, const char *ssid, const char *password)
{
  if (strcmp(mode, "STA") == 0)
  {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.printf("\n[STA Mode]: Connecting to WiFi: %s\n", ssid);

    int retries = 30;
    while (WiFi.status() != WL_CONNECTED && retries > 0)
    {
      delay(1000);
      Serial.print(".");
      retries--;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("\n[STA Mode]: Connected!");
      Serial.printf("[STA Mode]: IP Address: http://%s\n", WiFi.localIP().toString().c_str());
    }
    else
    {
      Serial.println("\n[STA Mode]: Connection Failed! Switching to AP Mode...");
      serverStart("AP", ssid, password);
      return;
    }
  }
  else if (strcmp(mode, "AP") == 0)
  {
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(IPAddress(192, 168, 4, 1), IPAddress(192, 168, 4, 1), IPAddress(255, 255, 255, 0));
    dnsServer.start(53, "*", IPAddress(192, 168, 4, 1));

    Serial.printf("\n[AP Mode]: Access Point Started!\n");
    Serial.printf("[AP Mode]: SSID: \"%s\"\n", ssid);
    Serial.printf("[AP Mode]: Password: \"%s\"\n", password);
    Serial.printf("[AP Mode]: AP IP Address: http://%s\n", WiFi.softAPIP().toString().c_str());
  }

  // 📌 Sayfaları tanımla
  serverCODROB.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                  {
      Serial.println("[Local Server]: Root URL Accessed!");
      request->send(200, "text/plain", "CODROB Server is Running!"); });

  // 📌 404 Hatası
  serverCODROB.onNotFound([](AsyncWebServerRequest *request)
                          {
      Serial.println("[Local Server]: Received an Unknown Request!");
      request->send(404, "text/plain", "Not Found"); });

  // 📌 **WebSocket Olaylarını Bağla**
  serverCODROBWebSocket->onEvent([](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
                                 {
      if (type == WS_EVT_CONNECT) {
          Serial.println("WebSocket Client Connected");
      } else if (type == WS_EVT_DISCONNECT) {
          Serial.println("WebSocket Client Disconnected");
      } });

  // 📌 WebSocket'i Sunucuya Bağla
  serverCODROB.addHandler(serverCODROBWebSocket);

  // 📌 **En son sunucuyu başlat!**
  serverCODROB.begin();
  Serial.println("[Local Server]: Server Started! ✅");
}

void MINIBOT::serverCreateLocalPage(const char *url, const char *WEBPageScript, const char *WEBPageCSS, const char *WEBPageHTML, size_t bufferSize)
{
  // 📌 Sayfa içeriğini oluştur
  serverCODROB.on(("/" + String(url)).c_str(), HTTP_GET, [WEBPageScript, WEBPageCSS, WEBPageHTML, bufferSize](AsyncWebServerRequest *request)
                  {
                    // Buffer boyutu kullanıcının belirttiği veya varsayılan değerle tanımlanır
                    char *buffer = new char[bufferSize];
                    int len = snprintf(buffer, bufferSize, WEBPageHTML, WEBPageScript, WEBPageCSS);

                    if (len >= bufferSize)
                    {
                      Serial.println("[ERROR]: Buffer size insufficient, content truncated!");
                    }

                    request->send(200, "text/html", buffer);
                    delete[] buffer; // Dinamik olarak ayrılan belleği serbest bırakın
                  });

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.printf("[Local Server]: Page created at: http://%s/%s\n", WiFi.localIP().toString().c_str(), url);
  }
  else
  {
    Serial.printf("[Local Server]: Page created at: http://%s/%s\n", apIP.toString().c_str(), url);
  }
}

void MINIBOT::serverHandleDNS()
{
  dnsServer.processNextRequest();
}

void MINIBOT::serverContinue()
{
  if (WiFi.getMode() == WIFI_AP)
  {
    serverHandleDNS();
  }
}
#endif

/*********************************** Firebase Server Functions ***********************************/
#if defined(USE_FIREBASE)
// Initialize Firebase connection with SignUp Authentication
void MINIBOT::fbServerSetandStartWithUser(const char *projectURL, const char *secretKey, const char *userMail, const char *mailPass)
{
  firebaseData.setResponseSize(1024); // Optimize memory usage

  // Firebase Configuration Settings
  firebaseConfig.api_key = secretKey;
  firebaseConfig.database_url = projectURL;
  firebaseAuth.user.email = userMail;
  firebaseAuth.user.password = mailPass;

  // Zaman aşımı ayarları
  firebaseConfig.timeout.socketConnection = 10 * 1000; // 10 saniye bağlantı zaman aşımı

  // Token durumu izleme ayarı
  // firebaseConfig.token_status_callback = tokenStatusCallback;
  firebaseConfig.max_token_generation_retry = 5; // Daha fazla token yenileme denemesi

  // Wi-Fi bağlantısı kaybolduğunda otomatik yeniden bağlanma
  Firebase.reconnectWiFi(true);

  // Firebase başlat
  Firebase.begin(&firebaseConfig, &firebaseAuth);

  Serial.println("[Firebase]: Verifying user credentials...");
  uint8_t id_count = 0;
  while (firebaseAuth.token.uid == "" && id_count < 50)
  {
    Serial.print('.');
    delay(500);
    id_count++;
  }
  if (firebaseAuth.token.uid == "")
  {
    Serial.println("\n[ERROR]: Authentication timeout.");
  }
  else
  {
    if (Firebase.ready())
    {
      strncpy(uid, firebaseAuth.token.uid.c_str(), 128 - 1); // UID'yi kopyala ve taşma kontrolü yap
      uid[128 - 1] = '\0';                                   // Diziyi null karakter ile sonlandır
      Serial.print("\n[Info]: Doğrulanan Kimlik ID: ");
      Serial.println(uid);
    }
    else
    {
      Serial.print("[ERROR]: Sign-up failed. Reason: ");
      Serial.println(firebaseData.errorReason());
    }
  }
}

/*********************************** Firebase Write Functions ***********************************/

void MINIBOT::fbServerSetInt(const char *dataPath, int data)
{
  // Corrected function call
  if (Firebase.RTDB.setInt(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: Integer data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send integer data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void MINIBOT::fbServerSetFloat(const char *dataPath, float data)
{
  if (Firebase.RTDB.setFloat(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: Float data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send float data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void MINIBOT::fbServerSetString(const char *dataPath, String data)
{
  if (Firebase.RTDB.setString(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: String data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send string data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void MINIBOT::fbServerSetDouble(const char *dataPath, double data)
{
  if (Firebase.RTDB.setDouble(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: Double data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send double data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void MINIBOT::fbServerSetBool(const char *dataPath, bool data)
{
  if (Firebase.RTDB.setBool(&firebaseData, dataPath, data))
  {
    Serial.println("[SUCCESS]: Boolean data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send boolean data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

void MINIBOT::fbServerSetJSON(const char *dataPath, String data)
{
  FirebaseJson json;
  json.set(dataPath, data);

  if (Firebase.RTDB.setJSON(&firebaseData, dataPath, &json))
  {
    Serial.println("[SUCCESS]: JSON data sent successfully!");
  }
  else
  {
    Serial.print("[ERROR]: Failed to send JSON data. ");
    Serial.printf("HTTP Code: %d\n", firebaseData.httpCode());
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

/*********************************** Firebase Read Functions ***********************************/

int MINIBOT::fbServerGetInt(const char *dataPath)
{
  if (Firebase.RTDB.getInt(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: Integer data retrieved successfully!");
    return firebaseData.intData();
  }
  Serial.println("[ERROR]: Failed to retrieve integer data.");
  return -1;
}

float MINIBOT::fbServerGetFloat(const char *dataPath)
{
  if (Firebase.RTDB.getFloat(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: Float data retrieved successfully!");
    return firebaseData.floatData();
  }
  Serial.println("[ERROR]: Failed to retrieve float data.");
  return -1.0;
}

String MINIBOT::fbServerGetString(const char *dataPath)
{
  if (Firebase.RTDB.getString(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: String data retrieved successfully!");
    return firebaseData.stringData();
  }
  Serial.println("[ERROR]: Failed to retrieve string data.");
  return "";
}

double MINIBOT::fbServerGetDouble(const char *dataPath)
{
  if (Firebase.RTDB.getDouble(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: Double data retrieved successfully!");
    return firebaseData.doubleData();
  }
  Serial.println("[ERROR]: Failed to retrieve double data.");
  return -1.0;
}

bool MINIBOT::fbServerGetBool(const char *dataPath)
{
  if (Firebase.RTDB.getBool(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: Boolean data retrieved successfully!");
    return firebaseData.boolData();
  }
  Serial.println("[ERROR]: Failed to retrieve boolean data.");
  return false;
}

String MINIBOT::fbServerGetJSON(const char *dataPath)
{
  if (Firebase.RTDB.getJSON(&firebaseData, dataPath))
  {
    Serial.println("[SUCCESS]: JSON data retrieved successfully!");
    return firebaseData.jsonString();
  }
  Serial.println("[ERROR]: Failed to retrieve JSON data.");
  return "{}";
}
#endif
