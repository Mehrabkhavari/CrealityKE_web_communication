#include <CrealityKE.h>

CrealityKE printer;

void setup()
{
    Serial.begin(115200);

    WiFi.begin("YOUR_WIFI", "YOUR_PASSWORD");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    printer.begin("192.168.1.100");
}

void loop()
{
    printer.loop();

    if (!printer.connected())
        return;

    // Set temperatures
    printer.setNozzleTemp(220);
    delay(1000);

    printer.setBedTemp(60);
    delay(1000);

    // Home printer
    printer.homeXYZ();
    delay(10000);

    // Pause printing
    printer.pause();
    delay(3000);

    // Resume printing
    printer.resume();
    delay(3000);

    // Stop printing
    printer.stop();

    while (true)
    {
        printer.loop();
    }
}