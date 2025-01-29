#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14
                        
void setup()
{
    minibot.begin();                                                         // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();                                                     // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200);                                             // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Welcome to MiniBot Traffic Lights Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
    // Kırmızı ışık / Red light
    minibot.moduleTraficLightWrite(true, false, false);
    minibot.serialWrite("Kirmizi Isik - Red Light"); // Display welcome message / Hoşgeldiniz mesajını göster
    delay(3000);

    // Sarı ışık / Yellow light
    minibot.moduleTraficLightWrite(false, true, false);
    minibot.serialWrite("Sari Isik - Yellow Light"); // Display welcome message / Hoşgeldiniz mesajını göster
    delay(3000);

    // Yeşil ışık / Green light
    minibot.moduleTraficLightWrite(false, false, true);
    minibot.serialWrite("Yesil Isik - Green Light"); // Display welcome message / Hoşgeldiniz mesajını göster
    delay(3000);
}
