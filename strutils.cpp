#include "strutils.h"

#include <QDebug>

using namespace STU;

StrUtils::StrUtils()
{

}

int StrUtils::SubIndex(const char *chStr, int nSize, char ch)
{
    char* chTmp = (char*)malloc(nSize);
    strcpy(chTmp, chStr);
    int j = 0;
    while(chTmp[j] != ch)
    {
        j++;
    }
    free(chTmp);
    return j;
}

QPoint STU::StrUtils::SplitStrToPt(QString strXY, char chIdle)
{
    char chX[20];
    qDebug() << "1--" << strXY;
    strcpy(chX, strXY.toStdString().data());
    int j = 0;
    while(chX[j] != chIdle)
    {
        j++;
    }
    qDebug() << "2--" << j;
    //const int num = j;
    //char chX1[num];
    char* chX1 = (char*)malloc(j);
    j = 0;
    while(chX[j] != chIdle)
    {
        chX1[j] = chX[j];
        j++;
    }
    qDebug() << "3--" << chX1;
    const char* chBufx = strchr(chX1, '=');
    strcpy(chX, chBufx);
    const int len = sizeof(chX);
    char chX2[len - 1];
    qDebug() << chX;
    j = 1;
    while(chX[j] != '\0' && chX[j] != '\n')
    {
        chX2[j - 1] = chX[j];
        j++;
    }
    qDebug() << "xy--" << chX2;
    const char* chBuf = strchr(strXY.toStdString().data(), chIdle);
    qDebug() << "4--" << chBuf;
    const char* chY = strchr(chBuf, '=');
    const int inx = sizeof(chY);
    char *chY1 = (char*)malloc(inx);
    char chY2[inx - 1];
    strcpy(chY1, chY);
    int i = 1;
    qDebug() << chY1;
    while(chY1[i] != '\0' && chY1[i] != '\n')
    {
        chY2[i-1] = chY1[i];
        i++;
    }

    qDebug() << i << "--------------------------" << chY2;

    QPoint pt = QPoint(atoi(chX2), atoi(chY2));
    qDebug() << pt.x() << "--" << pt.y();
    free(chX1);
    free(chY1);
    qDebug() << "end --";
    return pt;
}
