#include <WiFi.h>
#include <CrealityKE.h>

const char* ssid = "STARLINK-5FF7";
const char* password = "25493351";

CrealityKE printer;

unsigned long lastUpdate = 0;

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, password);

    Serial.print("Connecting");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected");

    printer.begin("192.168.0.157");
}

void loop()
{
    printer.loop();

    if (millis() - lastUpdate >= 1000)
    {
        lastUpdate = millis();

        Serial.println("===================================");

        Serial.println("DEVICE");

        Serial.print("Hostname      : ");
        Serial.println(printer.hostname());

        Serial.print("Model         : ");
        Serial.println(printer.model());

        Serial.print("Version       : ");
        Serial.println(printer.version());

        Serial.print("Connected     : ");
        Serial.println(printer.connected());

        Serial.print("Max Nozzle    : ");
        Serial.println(printer.maxNozzleTemp());

        Serial.print("Max Bed       : ");
        Serial.println(printer.maxBedTemp());

        Serial.println();

        Serial.println("TEMPERATURE");

        Serial.print("Nozzle        : ");
        Serial.println(printer.nozzleTemp());

        Serial.print("Target Nozzle : ");
        Serial.println(printer.targetNozzleTemp());

        Serial.print("Bed           : ");
        Serial.println(printer.bedTemp());

        Serial.print("Target Bed    : ");
        Serial.println(printer.targetBedTemp());

        Serial.println();

        Serial.println("PRINT");

        Serial.print("Progress      : ");
        Serial.println(printer.progress());

        Serial.print("Layer         : ");
        Serial.println(printer.currentLayer());

        Serial.print("Total Layer   : ");
        Serial.println(printer.totalLayers());

        Serial.print("Print Time    : ");
        Serial.println(printer.printTime());

        Serial.print("Remain Time   : ");
        Serial.println(printer.remainingTime());

        Serial.print("State         : ");
        Serial.println(printer.state());

        Serial.println();

        Serial.println("COOLING");

        Serial.print("Fan           : ");
        Serial.println(printer.fan());

        Serial.print("Model Fan     : ");
        Serial.println(printer.modelFan());

        Serial.print("Case Fan      : ");
        Serial.println(printer.caseFan());

        Serial.print("Aux Fan       : ");
        Serial.println(printer.auxiliaryFan());

        Serial.println();

        Serial.println("FILAMENT");

        Serial.print("Sensor Enable : ");
        Serial.println(printer.materialDetected());

        Serial.print("Material      : ");
        Serial.println(printer.materialStatus());

        Serial.println("===================================");
        Serial.println();
    }
}