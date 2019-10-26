#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum DetectType{
    nNone = -1,
    nDetArea,
    nTriLine,
    nTotal
};

typedef struct _ImageData
{
    int nWidth;
    int nHeight;
    QString strImagePath;
    _ImageData()
    {
        nWidth = 0;
        nHeight = 0;
        strImagePath = "";
    }
}ImageData;

#define GS(valueType, valueName)    \
private:                            \
    valueType m_##valueName;           \
public:                                \
    valueType Get##valueName##(){ return m_##valueName;} \
    void Set##valueName##(valueType value){ m_##valueName = value;}

#endif // COMMON_H
