#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14
                        
void setup()
{
    minibot.begin();             // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();         // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200); // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Welcome to MiniBot Magnetic Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
    bool magneticStatus = minibot.moduleMagneticRead(SENSOR_PIN); // Manyetik sensör durumu okunuyor / Read magnetic sensor status

    minibot.serialWrite("Manyetik Sensör Durumu / Magnetic Sensor Status: ");
    minibot.serialWrite(magneticStatus); // Manyetik sensör durumu yazdırılıyor / Print magnetic sensor status

    delay(500); // 500 ms bekle / Wait for 500 ms
}
