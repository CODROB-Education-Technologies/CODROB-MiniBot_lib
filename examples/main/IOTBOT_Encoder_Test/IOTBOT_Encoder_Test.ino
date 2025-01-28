#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Encoder testi başlatıldı / Encoder test started.");
}

void loop()
{
    static unsigned long previousMillis = 0;
    const long interval = 500; // Yarım saniyede bir yazdırma için 500 milisaniye / Wait 500ms

    unsigned long currentMillis = millis();
    int encoderValue = iotbot.encoderRead();       // Encoder değeri okunuyor / Read encoder value
    int buttonStatus = iotbot.encoderButtonRead(); // Encoder buton durumu okunuyor / Read encoder button status

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        iotbot.serialWrite("Encoder Değeri / Encoder Value: ");
        iotbot.serialWrite(encoderValue); // Encoder değeri yazdırılıyor / Print encoder value
        iotbot.serialWrite("Encoder Buton Durumu / Encoder Button Status: ");
        iotbot.serialWrite(buttonStatus); // Encoder buton durumu yazdırılıyor / Print encoder button status
    }
}