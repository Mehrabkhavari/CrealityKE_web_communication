#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>
#include <WebSocketsClient.h>

// چون فقط Pointer نیاز داریم، نیازی نیست کل Parser.h
// اینجا Include شود.
// این کار زمان کامپایل را کاهش می‌دهد.
class Parser;

/*
    ===================================================================

    Connection

    مسئول برقراری ارتباط با پرینتر

    وظایف:

        - اتصال WebSocket
        - مدیریت Reconnect
        - دریافت پیام‌ها
        - ارسال پیام‌ها (در نسخه‌های بعد)

    این کلاس هیچ اطلاعی از JSON ندارد.

    ===================================================================
*/

class Connection
{
public:

    Connection();

    /*
        اتصال به پرینتر

        ip:
            آدرس IP پرینتر

        parser:
            آدرس شی Parser
            هر پیامی دریافت شود به Parser ارسال خواهد شد.
    */
    void begin(
        const char* ip,
        Parser* parser,
        uint16_t port = 9999);

    /*
        باید داخل loop اصلی برنامه فراخوانی شود.

        این تابع مسئول پردازش ارتباط WebSocket است.
    */
    void loop();

private:

    // شی کتابخانه WebSocket
    WebSocketsClient ws;

    // اشاره‌گر به Parser
    Parser* _parser;

    /*
        چون Callback کتابخانه WebSocket استاتیک است،
        به اعضای کلاس دسترسی ندارد.

        بنابراین از Singleton ساده استفاده می‌کنیم
        تا Callback بتواند نمونه فعلی کلاس را پیدا کند.
    */
    static Connection* instance;

    /*
        Callback اصلی WebSocket

        این تابع فقط پیام را به نمونه واقعی کلاس منتقل می‌کند.
    */
    static void webSocketEvent(
        WStype_t type,
        uint8_t* payload,
        size_t length);

    /*
        پردازش واقعی Eventها

        این تابع عضو کلاس است و به تمام متغیرها
        دسترسی دارد.
    */
    void onMessage(
        WStype_t type,
        uint8_t* payload,
        size_t length);

};

#endif