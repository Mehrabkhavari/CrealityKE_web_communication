#include "CrealityKE.h"

/*
    Constructor

    اینجا ارتباط بین Parser و PrinterStatus برقرار می‌شود.

    از این لحظه هر اطلاعاتی که Parser استخراج کند،
    مستقیماً داخل status ذخیره خواهد شد.
*/
CrealityKE::CrealityKE()
{
    parser.begin(&status);
}

/*
    شروع ارتباط با پرینتر
*/
void CrealityKE::begin(
    const char* ip,
    uint16_t port)
{
    connection.begin(ip, &parser, port);
}

/*
    پردازش ارتباط WebSocket
*/
void CrealityKE::loop()
{
    connection.loop();
}