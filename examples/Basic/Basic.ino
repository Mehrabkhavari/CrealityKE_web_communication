#include <WiFi.h>
#include <CrealityKE.h>

/*
    اطلاعات شبکه
*/
const char* ssid = "YOUR_WIFI";

const char* password = "YOUR_PASSWORD";

/*
    ساخت شی کتابخانه
*/
CrealityKE printer;

void setup()
{
    Serial.begin(115200);

    /*
        اتصال به WiFi
    */
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected");

    /*
        اتصال به پرینتر

        فقط IP لازم است.

        پورت به صورت پیش‌فرض 9999 است.
    */
    printer.begin("192.168.0.156");
}

void loop()
{
    /*
        این تابع باید دائماً اجرا شود.

        در غیر این صورت ارتباط WebSocket
        متوقف خواهد شد.
    */
    printer.loop();
}