#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14
void setup()
{
    minibot.begin();                                                    // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();                                                // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200);                                        // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Welcome to MiniBot Vibration Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
    bool vibrationStatus = minibot.moduleVibrationDigitalRead(SENSOR_PIN); // Titreşim durumu okunuyor / Read vibration status
    if (vibrationStatus)
    {
        minibot.serialWrite("Titresim Durumu / Vibration Status: ");
        minibot.serialWrite(vibrationStatus); // Titreşim durumu yazdırılıyor / Print vibration status
    }

    delay(100); // 500 ms bekle / Wait for 500 ms
}
