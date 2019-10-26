#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include <QString>
#include "detector.h"
#include "common.h"
#include <vector>
#include <mxml.h>

class XMLManager
{
public:
    XMLManager(QString strXMLPath = "");
    ~XMLManager();

    void LoadXML(QString strXMLPath = "");

    int SaveXML(QString strXMLPath = "");

    int SetDetectorData(const std::vector<Detector*> arrDetector);
    int GetDetectorData(std::vector<Detector*>& arrDetector);

    void SetImageData(ImageData *pImgData);
    void GetImageData(ImageData *pImgData);

    ImageData* GetImageData();

    void ClearData(){ m_arrDetector.clear();}

private:
    QString m_strPath;
    std::vector<Detector*> m_arrDetector;   //所有检测类
    ImageData * m_pImageData;
};

#endif // XMLMANAGER_H
