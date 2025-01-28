#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Titreşim sensör testi başlatıldı / Vibration sensor test started.");
}

void loop()
{
    int vibrationStatus = iotbot.moduleVibrationAnalogRead(SENSOR_PIN); // Titreşim durumu okunuyor / Read vibration status

    iotbot.serialWrite("Titresim Durumu / Vibration Status: ");
    iotbot.serialWrite(vibrationStatus); // Titreşim durumu yazdırılıyor / Print vibration status

    delay(100); // 500 ms bekle / Wait for 500 ms
}
