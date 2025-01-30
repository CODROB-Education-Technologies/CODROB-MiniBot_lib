#include <MINIBOT.h> // MINIBOT kütüphanesi / MINIBOT library

// MINIBOT nesnesi oluşturuluyor / Create a MINIBOT object
MINIBOT minibot;

#define SENSOR_PIN IO12 // Sensörün bağlı olduğu pini seçin / Select the sensor pin
// Desteklenen pinler: IO4 - IO5 - IO12 - IO13 - IO14
// Supported pins: IO4 - IO5 - IO12 - IO13 - IO14

void setup()
{
    minibot.begin(); // MINIBOT başlat / Initialize MINIBOT

    minibot.serialStart(115200); // Seri haberleşmeyi 115200 baud hızıyla başlat / Start serial communication at 115200 baud
    // Bilgisayar ile seri haberleşme için 115200 baud hızında başlatılır.
    // Starts serial communication at 115200 baud for computer connection.

    minibot.serialWrite("IR Okuyucu testi başlatıldı / IR Reader test started.");
    // IR sensör testinin başladığını seri porta yazdır / Print IR sensor test start message to the serial port

    delay(2000); // Başlangıç gecikmesi (2 saniye) / Initial delay (2 seconds)
}

void loop()
{
    // IR sensöründen gelen Decimal verisini oku / Read Decimal data from IR sensor
    long value = minibot.moduleIRReadDecimalx32(SENSOR_PIN);
    // Alternatif olarak 8-bit formatında değer almak için aşağıdaki satırı kullanabilirsiniz:
    // Alternatively, use the following line to get an 8-bit formatted value:
    // long value = minibot.moduleIRReadDecimalx8(SENSOR_PIN);

    // Eğer geçerli bir veri alındıysa (sıfır değilse) / If valid data is received (not "0")
    if (value != 0)
    {
        // Seri port üzerinden Decimal kodunu gönder / Send Decimal code via serial port
        minibot.serialWrite("Decimal Code:");
        minibot.serialWrite(value);
    }
}
