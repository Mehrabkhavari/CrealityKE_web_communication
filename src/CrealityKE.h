#ifndef CREALITYKE_H
#define CREALITYKE_H

#include "Connection.h"
#include "Parser.h"
#include "Status.h"
#include "Commands.h"

/*
    ===============================================================

    CrealityKE

    این کلاس تنها کلاسی است که کاربر کتابخانه با آن کار می‌کند.

    هدف این است که کاربر هیچ نیازی به دانستن جزئیات داخلی
    مانند WebSocket، Parser یا JSON نداشته باشد.

    معماری داخلی کتابخانه:

            User
              │
              ▼
         CrealityKE
        ├──────────┐
        ▼          ▼
    Connection   Parser
                     │
                     ▼
               PrinterStatus

    ===============================================================
*/

class CrealityKE
{
public:

    CrealityKE();

    /*
        اتصال به پرینتر

        ip:
            آدرس IP پرینتر

        port:
            پورت WebSocket
            مقدار پیش‌فرض 9999 است.
    */
    void begin(
        const char* ip,
        uint16_t port = 9999);

    /*
        باید داخل loop برنامه اجرا شود.
    */
    void loop();

private:

    /*
        مدیریت ارتباط
    */
    Connection connection;

    /*
        تجزیه پیام‌ها
    */
    Parser parser;

    /*
        وضعیت فعلی پرینتر

        Parser اطلاعات دریافتی را داخل این Struct
        ذخیره خواهد کرد.
    */
    PrinterStatus status;

    /*
        دستورات ارسالی

        فعلاً استفاده نمی‌شود.
    */
    Commands commands;

};

#endif