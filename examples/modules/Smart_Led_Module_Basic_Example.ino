/*
 * This code is designed for the CODROB Smart LED Module.
 * Created to demonstrate the use of NeoPixel LED effects with CODROB IoTBOT.
 *
 * CODROB Akıllı LED Modülü için tasarlanmıştır.
 * Bu kod, NeoPixel LED efektlerini kullanmayı göstermek amacıyla oluşturulmuştur.
 */

#include <IOTBOT.h>

// Create an IoTBOT object / IoTBOT sınıfından bir nesne oluşturulur
IOTBOT iotbot;

#define SENSOR_PIN IO27 // Select sensor pin / Sensörün bağlı olduğu pini seçin.
                        // IO25 - IO26 - IO27 - IO32 - IO33

void setup()
{
    // Initialize NeoPixel strip (Pin: GPIO 27, LED Count: 3)
    // NeoPixel şeridini başlat (Pin: GPIO 27, LED Sayısı: 3)
    iotbot.moduleSmartLEDPrepare(SENSOR_PIN); //(I025, IO26,IO27,IO32,IO33)

    // Set initial LED colors / Başlangıç renklerini ayarla
    delay(1000);
    iotbot.moduleSmartLEDWrite(0, 255, 0, 0); // LED 0: Red / Kırmızı
    delay(1000);
    iotbot.moduleSmartLEDWrite(1, 0, 255, 0); // LED 1: Green / Yeşil
    delay(1000);
    iotbot.moduleSmartLEDWrite(2, 0, 0, 255); // LED 2: Blue / Mavi
    delay(1000);
}

void loop()
{
    // Run Rainbow Effect / Gökkuşağı Efektini Çalıştır
    iotbot.moduleSmartLEDRainbowEffect(50); // Smooth rainbow effect / Yumuşak gökkuşağı efekti
    delay(1000);

    // Run Rainbow Theater Chase Effect / Gökkuşağı Tiyatro Takip Efekti
    iotbot.moduleSmartLEDRainbowTheaterChaseEffect(50); // Rainbow theater chase / Gökkuşağı tiyatro ışığı
    delay(1000);

    // Run Red Theater Chase Effect / Kırmızı Tiyatro Takip Efekti
    iotbot.moduleSmartLEDTheaterChaseEffect(iotbot.getColor(255, 0, 0), 50); // Red theater chase / Kırmızı tiyatro ışığı
    delay(1000);

    // Run Blue Color Wipe Effect / Mavi Renk Temizleme Efekti
    iotbot.moduleSmartLEDColorWipeEffect(iotbot.getColor(0, 0, 255), 50); // Blue color wipe / Mavi renk temizleme
    delay(1000);
}
