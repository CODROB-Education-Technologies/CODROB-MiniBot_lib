#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Toprak nem sensör testi başlatıldı / Soil moisture sensor test started.");
}

void loop()
{
    int soilMoisture = iotbot.moduleSoilMoistureRead(SENSOR_PIN); // Toprak nem değeri okunuyor / Read soil moisture value

    iotbot.serialWrite("Toprak Nem Değeri / Soil Moisture Value: ");
    iotbot.serialWrite(soilMoisture); // Toprak nem değeri yazdırılıyor / Print soil moisture value

    delay(1000); // 1 saniye bekle / Wait for 1 second
}
