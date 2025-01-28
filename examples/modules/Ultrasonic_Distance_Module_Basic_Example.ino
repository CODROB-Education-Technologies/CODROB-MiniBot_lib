#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Ultrasonik sensör testi başlatıldı / Ultrasonic sensor test started.");
}

void loop()
{
    int distance = iotbot.moduleUltrasonicDistanceRead(); // Mesafe ölçülüyor / Measure distance

    iotbot.serialWrite("Mesafe / Distance: ");
    iotbot.serialWrite(distance); // Mesafe yazdırılıyor / Print distance

    delay(1000); // 1 saniye bekle / Wait for 1 second
}
