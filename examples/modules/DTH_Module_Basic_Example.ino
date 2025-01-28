#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("DHT sensör testi başlatıldı / DHT sensor test started.");
}

void loop()
{
    int temperature = iotbot.moduleDhtTempRead(SENSOR_PIN); // Sıcaklık değeri okunuyor / Read temperature
    int humidity = iotbot.moduleDhtHumRead(SENSOR_PIN);     // Nem değeri okunuyor / Read humidity

    iotbot.serialWrite("Sıcaklık / Temperature: ");
    iotbot.serialWrite(temperature); // Sıcaklık yazdırılıyor / Print temperature
    iotbot.serialWrite("Nem / Humidity: ");
    iotbot.serialWrite(humidity); // Nem yazdırılıyor / Print humidity

    delay(2000); // 2 saniye bekle / Wait for 2 seconds
}
