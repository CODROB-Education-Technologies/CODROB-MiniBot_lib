#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// Create a MINIBOT object / MINIBOT nesnesi oluşturuluyor
MINIBOT minibot;

#define SENSOR_PIN IO12 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO4 - IO5 - IO12 - IO13 - IO14
                        
void setup()
{
    minibot.begin();                                                // Initialize MINIBOT / MINIBOT başlatılıyor
    minibot.playIntro();                                            // Play startup melody / Giriş müziği çalınıyor
    minibot.serialStart(115200);                                    // Start serial communication / Seri haberleşmeyi başlat
    minibot.serialWrite("Welcome to MiniBot Relay Test Firmware!"); // Display welcome message / Hoşgeldiniz mesajını göster
}

void loop()
{
    // Röleyi aktif hale getir / Activate the relay
    minibot.moduleRelayWrite(SENSOR_PIN, true);
    minibot.serialWrite("Relay ON - Röle Devrede!");
    delay(3000);

    // Röleyi pasif hale getir / Deactivate the relay
    minibot.moduleRelayWrite(SENSOR_PIN, false);
    minibot.serialWrite("Relay OFF - Röle Devre Dışı!");
    delay(3000);
}
