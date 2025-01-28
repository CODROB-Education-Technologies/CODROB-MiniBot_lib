#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("DC Motor", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    // Saat yönünde hareket / Clockwise motion
    iotbot.moduleDCMotorGOClockWise(50); // Hız %50 / Speed 50%
    iotbot.lcdClear();
    iotbot.lcdWriteMid("DC Motor", "Direction:", "Clockwise", "Speed: 50%");
    delay(3000);

    // Saat yönünün tersine hareket / Counterclockwise motion
    iotbot.moduleDCMotorGOCounterClockWise(75); // Hız %75 / Speed 75%
    iotbot.lcdClear();
    iotbot.lcdWriteMid("DC Motor", "Direction:", "CounterClockwise", "Speed: 75%");
    delay(3000);

    // Motoru durdur / Stop motor
    iotbot.moduleDCMotorStop();
    iotbot.lcdClear();
    iotbot.lcdWriteMid("DC Motor", "Motor Stopped", "", "");
    delay(3000);
}
