#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Potansiyometre testi başlatıldı / Potentiometer test started.");
}

void loop()
{
    int potValue = iotbot.potentiometerRead(); // Potansiyometre değeri okunuyor / Read potentiometer value
    iotbot.serialWrite("Potansiyometre Değeri / Potentiometer Value: ");
    iotbot.serialWrite(potValue); // Potansiyometre değeri yazdırılıyor / Print potentiometer value

    delay(500); // Test için kısa bir gecikme / Short delay for testing
}
