#include <WiFi.h>
#include <CrealityKE.h>

const char* ssid="YOUR_WIFI";
const char* password="YOUR_PASSWORD";

CrealityKE printer;

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid,password);

    while(WiFi.status()!=WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected");

    printer.begin("192.168.0.156");
}

void loop()
{
    printer.loop();
}