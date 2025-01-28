#include <IOTBOT.h> // IoTBot kütüphanesi / IoTBot library

IOTBOT iotbot;

void setup()
{
    iotbot.begin();
    iotbot.serialStart(115200);
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Stepper Motor", "--- IoTBot ---", "Test Basladi", "Test Started");
    delay(3000);
}

void loop()
{
    // Saat yönünde hareket / Clockwise motion
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Stepper Motor", "Direction:", "Clockwise", "Steps: 100");
    iotbot.moduleStepMotorMotion(50, true, 100, 60); // 100 adım, saat yönü, hız 60 RPM / 100 steps, clockwise, 60 RPM
    delay(3000);

    // Saat yönünün tersine hareket / Counterclockwise motion
    iotbot.lcdClear();
    iotbot.lcdWriteMid("Stepper Motor", "Direction:", "CounterClockwise", "Steps: 100");
    iotbot.moduleStepMotorMotion(50, false, 100, 60); // 100 adım, saat yönü tersi, hız 60 RPM / 100 steps, counterclockwise, 60 RPM
    delay(3000);
}
