#include "Parser.h"

/*
    Constructor

    هنگام ساخته شدن کلاس، هنوز آدرس PrinterStatus
    مشخص نیست.

    بنابراین Pointer را nullptr قرار می‌دهیم.
*/
Parser::Parser()
{
    _status = nullptr;
}

/*
    begin()

    آدرس PrinterStatus را ذخیره می‌کند.

    از این به بعد Parser می‌تواند اطلاعات پرینتر را
    مستقیماً داخل همین Struct بنویسد.
*/
void Parser::begin(PrinterStatus* status)
{
    _status = status;
}

/*
    parse()

    این تابع هر بار که پیامی از پرینتر دریافت شود اجرا می‌شود.

    فعلاً فقط پیام را نمایش می‌دهد.

    در نسخه‌های بعدی:

    - JSON تجزیه می‌شود.
    - فیلدهای مورد نیاز استخراج می‌شوند.
    - مقادیر داخل PrinterStatus نوشته می‌شوند.
*/
void Parser::parse(const String& payload)
{
    Serial.println();
    Serial.println("========== Parser ==========");

    Serial.println(payload);

    Serial.println("============================");

    /*
        اگر begin() اجرا نشده باشد
        نباید هیچ عملی انجام دهیم.
    */
    if (_status == nullptr)
        return;

    /*
        فعلاً هیچ پردازشی انجام نمی‌شود.

        مثال نسخه بعد:

        _status->nozzleTemp = ...

        _status->bedTemp = ...

        _status->progress = ...
    */
}