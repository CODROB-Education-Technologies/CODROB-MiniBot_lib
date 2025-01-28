#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Buzzer testi başlatıldı / Buzzer test started.");
}

void loop()
{
    iotbot.serialWrite("Buzzer çalıyor / Buzzer playing...");
    iotbot.buzzerPlayTone(1000, 500); // 1000 Hz frekansında 500 ms çalıyor / Play at 1000 Hz for 500 ms
    delay(1000);                      // Kısa gecikme / Short delay
}
