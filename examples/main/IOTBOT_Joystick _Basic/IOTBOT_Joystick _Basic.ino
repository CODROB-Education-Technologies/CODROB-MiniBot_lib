#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot; // IoTBot nesnesi oluşturuluyor / Create IoTBot object

void setup()
{
    iotbot.begin();             // IoTBot başlatılıyor / Initialize IoTBot
    iotbot.serialStart(115200); // Seri iletişim başlatılıyor / Start serial communication
    iotbot.serialWrite("Joystick testi başlatıldı / Joystick test started.");
}

void loop()
{
    int xValue = iotbot.joystickXRead();      // Joystick X ekseni değeri okunuyor / Read joystick X-axis value
    int yValue = iotbot.joystickYRead();      // Joystick Y ekseni değeri okunuyor / Read joystick Y-axis value
    int button = iotbot.joystickButtonRead(); // Joystick buton durumu okunuyor / Read joystick button state

    iotbot.serialWrite("Joystick X: ");
    iotbot.serialWrite(xValue); // X ekseni değeri yazdırılıyor / Print X-axis value
    iotbot.serialWrite("Joystick Y: ");
    iotbot.serialWrite(yValue); // Y ekseni değeri yazdırılıyor / Print Y-axis value
    iotbot.serialWrite("Joystick Button: ");
    iotbot.serialWrite(button); // Buton durumu yazdırılıyor / Print button state

    delay(500); // Test için kısa bir gecikme / Short delay for testing
}
