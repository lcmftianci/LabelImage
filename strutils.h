#ifndef STRUTILS_H
#define STRUTILS_H

#include <QPoint>

namespace STU{

    class StrUtils
    {
    public:
        StrUtils();

    private:
        int SubIndex(const char *chStr, int nSize, char ch = ' ');

    public:
        static QPoint SplitStrToPt(QString strXY, char chIdle = ' ');


    };


}

#endif // STRUTILS_H
