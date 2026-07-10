#include "Connection.h"
#include "Parser.h"

// اشاره‌گر Singleton
Connection* Connection::instance = nullptr;

/*
    Constructor

    هر بار که Connection ساخته شود،
    آدرس آن داخل instance ذخیره می‌شود.

    Callbackهای استاتیک از این آدرس
    برای دسترسی به کلاس استفاده می‌کنند.
*/
Connection::Connection()
{
    instance = this;
}

/*
    begin()

    اتصال WebSocket را برقرار می‌کند.
*/
void Connection::begin(
    const char* ip,
    Parser* parser,
    uint16_t port)
{
    // ذخیره آدرس Parser
    _parser = parser;

    // شروع اتصال
    ws.begin(ip, port, "/");

    // ثبت Callback
    ws.onEvent(webSocketEvent);

    // در صورت قطع ارتباط
    // هر پنج ثانیه دوباره تلاش می‌کند.
    ws.setReconnectInterval(5000);
}

/*
    این تابع باید دائماً اجرا شود.

    اگر فراخوانی نشود
    هیچ پیامی دریافت نخواهد شد.
*/
void Connection::loop()
{
    ws.loop();
}

/*
    Callback استاتیک

    این تابع مستقیماً توسط کتابخانه WebSocket
    صدا زده می‌شود.

    چون استاتیک است
    به اعضای کلاس دسترسی ندارد.

    بنابراین Event را به نمونه واقعی کلاس
    منتقل می‌کنیم.
*/
void Connection::webSocketEvent(
    WStype_t type,
    uint8_t* payload,
    size_t length)
{
    if(instance)
    {
        instance->onMessage(type, payload, length);
    }
}

/*
    تمام Eventهای WebSocket
    اینجا پردازش می‌شوند.
*/
void Connection::onMessage(
    WStype_t type,
    uint8_t* payload,
    size_t length)
{
    switch(type)
    {

        /*
            اتصال موفق
        */
        case WStype_CONNECTED:

            Serial.println();
            Serial.println("================================");
            Serial.println("Connected to Printer");
            Serial.println("================================");

            break;

        /*
            قطع ارتباط
        */
        case WStype_DISCONNECTED:

            Serial.println();
            Serial.println("================================");
            Serial.println("Printer Disconnected");
            Serial.println("================================");

            break;

        /*
            پیام متنی از پرینتر

            این مهم‌ترین قسمت کلاس است.

            از اینجا به بعد Connection دیگر
            هیچ اطلاعی از محتوای پیام ندارد.

            فقط آن را به Parser تحویل می‌دهد.
        */
        case WStype_TEXT:

            if(_parser)
            {
                _parser->parse(String((char*)payload));
            }

            break;

        /*
            فعلاً سایر Eventها
            استفاده نمی‌شوند.
        */
        default:

            break;

    }
}