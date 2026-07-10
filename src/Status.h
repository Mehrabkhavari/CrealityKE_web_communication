#ifndef STATUS_H
#define STATUS_H

#include <Arduino.h>

/*
    --------------------------------------------------------------------
    PrinterStatus

    این Struct حافظه‌ای برای نگهداری آخرین وضعیت پرینتر است.

    Parser بعد از دریافت هر پیام از پرینتر، مقادیر داخل این Struct
    را به‌روزرسانی می‌کند.

    بنابراین هیچ کدام از کلاس‌های دیگر مستقیماً JSON را پردازش
    نمی‌کنند و فقط اطلاعات را از این Struct می‌خوانند.

    در آینده تمام وضعیت پرینتر فقط از همین Struct قابل دسترسی خواهد بود.

    مثال:

    printer.status().nozzleTemp
    printer.status().bedTemp
    printer.status().progress
    printer.status().state

    --------------------------------------------------------------------
*/

struct PrinterStatus
{
    //==================== Temperatures ====================//

    // دمای فعلی نازل
    float nozzleTemp = 0;

    // دمای فعلی تخت
    float bedTemp = 0;

    // دمای هدف نازل
    float targetNozzleTemp = 0;

    // دمای هدف تخت
    float targetBedTemp = 0;

    //==================== Printing ====================//

    // درصد پیشرفت چاپ
    int progress = 0;

    // شماره لایه فعلی
    int layer = 0;

    // تعداد کل لایه‌ها
    int totalLayer = 0;

    // مدت زمان سپری شده از چاپ (ثانیه)
    int printTime = 0;

    // زمان باقی‌مانده (ثانیه)
    int remainTime = 0;

    //==================== Printer ====================//

    // وضعیت فعلی پرینتر
    //
    // مقدار این متغیر بعداً به Enum تبدیل خواهد شد.
    //
    // فعلاً نمونه:
    //
    // 0 = Idle
    // 1 = Printing
    // 2 = Pause
    //
    int state = 0;

    // وضعیت فن اصلی
    int fan = 0;

    // نام فایل در حال چاپ
    String fileName = "";
};

#endif