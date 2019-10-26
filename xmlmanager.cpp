#include "xmlmanager.h"
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include "strutils.h"
#include <QPoint>
#include <QDebug>

using namespace STU;



XMLManager::XMLManager(QString strXMLPath)
{
    m_strPath = strXMLPath;
    m_pImageData = new ImageData;
}

XMLManager::~XMLManager()
{
    delete m_pImageData;
}

//解析xml文件
void XMLManager::LoadXML(QString strXMLPath)
{
       mxml_node_t *tree, *node, *ImageDetect, *ImageSrc,
               *Detect, *DetectArea, *TriLine, *ImagePath;
       m_arrDetector.clear();
#if 0
       FILE *fp;
       fp = fopen(strXMLPath.toStdString().data(), "r");
       tree = mxmlLoadFile(NULL, fp, MXML_TEXT_CALLBACK);
       fclose(fp);
#endif
       QFile file(strXMLPath);
       char chBuf[200000];
       if(file.open(QIODevice::ReadOnly | QIODevice::Text)) //以文本文式写入
       {
           strcpy(chBuf, file.readAll().toStdString().data());
           //tree = mxmlLoadString(NULL, chBuf,MXML_TEXT_CALLBACK);
           tree = mxmlLoadString(NULL, chBuf, MXML_OPAQUE_CALLBACK);
           file.close();
       }

       qDebug() << "open OK";
       if(tree != NULL)
       {
           ImageDetect = mxmlFindElement(tree, tree, "ImageDetect", NULL, NULL, MXML_DESCEND);
           if(ImageDetect != NULL)
           {
               ImageSrc = mxmlFindElement(ImageDetect, tree, "ImageSrc", NULL, NULL, MXML_DESCEND);
               if(ImageSrc != NULL)
               {
                   node = mxmlFindElement(ImageSrc, tree, "Width", NULL, NULL, MXML_DESCEND);
                   //qDebug() << node->child->value.text.string;
                   qDebug() << node->child->value.opaque;
                   QString strNode(node->child->value.opaque);
                   m_pImageData->nWidth = strNode.toInt();
                   qDebug() << m_pImageData->nHeight;
                   node = mxmlFindElement(ImageSrc, tree, "Height", NULL, NULL, MXML_DESCEND);
                   qDebug() << node->child->value.opaque;
                   m_pImageData->nHeight = strNode.toInt();
                   node = mxmlFindElement(tree, tree, "ImagePath", NULL, NULL, MXML_DESCEND);
                   //qDebug() << node->child->value.opaque;
                   qDebug() << "DetectArea";
                   qDebug() << m_pImageData->strImagePath;
                   qDebug() << "DetectArea 55";
                   m_pImageData->strImagePath = QString(node->child->value.opaque);
                    qDebug() << "DetectArea 55";
               }

               qDebug() << "DetectArea";
               Detect = mxmlFindElement(ImageDetect, tree, "Detect", NULL, NULL, MXML_DESCEND);
               if(Detect != NULL)
               {
                   DetectArea = mxmlFindElement(Detect, tree, "DetectArea", NULL, NULL, MXML_DESCEND);
                   if(DetectArea)
                   {
                       node = mxmlFindElement(DetectArea, tree, "point", NULL, NULL, MXML_DESCEND);
                       if(node)
                       {
                           Detector*  pDetector = new Detector;
                           qDebug() << "DetectArea  1";
                           QString strNode = node->child->value.opaque;
                           qDebug() << strNode;
                           QPoint pt = StrUtils::SplitStrToPt(strNode, ' ');
                           qDebug() << pt.x() << "-- == "<< pt.y();
                           pDetector->PushPoint(pt);
                           //qDebug() << strNode;
                           while(1)
                           {
                               node = mxmlGetNextSibling(node);
                               if(!node)
                                   break;
                               if(mxmlGetType(node) == 0)
                               {
                                   strNode = node->child->value.opaque;
                                   qDebug() << strNode;
                                   QPoint pt = StrUtils::SplitStrToPt(strNode, ' ');
                                   qDebug() << pt.x() << "-- == "<< pt.y();
                                   pDetector->PushPoint(pt);
                               }
                           }
                           pDetector->SetType(nDetArea);
                           m_arrDetector.push_back(pDetector);
                       }
                       while(1)
                       {
                           DetectArea = mxmlGetNextSibling(DetectArea);
                           if(!DetectArea)
                               break;
                           qDebug() << "bb";
                           qDebug() << "Element==" << mxmlGetElement(DetectArea);
                           QString strTmp(mxmlGetElement(DetectArea));
                           strTmp = strTmp.trimmed();
                           if(!(strTmp.compare(QString("DetectArea").trimmed()) == 0))
                               continue;

                           //qDebug() << "Element---" << mxmlGetElement(DetectArea);
                           if(mxmlGetType(DetectArea) == 0)
                           {
                                Detector*  pDetector = new Detector;
                                 qDebug() << "DetectArea  2";
                               //strNode = node->child->value.text.string;
                               node = mxmlFindElement(DetectArea, tree, "point", NULL, NULL, MXML_DESCEND);
                               if(node)
                               {
                                   QString strNode = node->child->value.opaque;
                                   qDebug() << strNode;
                                   QPoint pt = StrUtils::SplitStrToPt(strNode, ' ');
                                   qDebug() << pt.x() << "-- == "<< pt.y();
                                   pDetector->PushPoint(pt);
                                   while(1)
                                   {
                                       node = mxmlGetNextSibling(node);
                                       if(!node)
                                           break;
                                       if(mxmlGetType(node) == 0)
                                       {
                                           strNode = node->child->value.opaque;
                                           qDebug() << strNode;
                                           QPoint pt = StrUtils::SplitStrToPt(strNode, ' ');
                                           qDebug() << pt.x() << "-- == "<< pt.y();
                                           pDetector->PushPoint(pt);
                                       }
                                   }
                                   pDetector->SetType(nDetArea);
                                   m_arrDetector.push_back(pDetector);
                               }
                           }
                       }
                   }

                   TriLine = mxmlFindElement(Detect, tree, "TriLine", NULL, NULL, MXML_DESCEND);
                   if(TriLine)
                   {
                       node = mxmlFindElement(TriLine, tree, "point", NULL, NULL, MXML_DESCEND);
                       if(node)
                       {
                           Detector*  pDetector = new Detector;
                           qDebug() << "TriLine  1";
                           QString strNode = node->child->value.opaque;
                           qDebug() << strNode;
                           QPoint pt = StrUtils::SplitStrToPt(strNode, ' ');
                           qDebug() << pt.x() << "-- == "<< pt.y();
                           pDetector->PushPoint(pt);
                           while(1)
                           {
                               node = mxmlGetNextSibling(node);
                               if(!node)
                                   break;
                               if(mxmlGetType(node) == 0)
                               {
                                   strNode = node->child->value.opaque;
                                   qDebug() << strNode;
                                   QPoint pt = StrUtils::SplitStrToPt(strNode, ' ');
                                   qDebug() << pt.x() << "-- == "<< pt.y();
                                   pDetector->PushPoint(pt);
                               }
                           }
                           pDetector->SetType(nTriLine);
                           m_arrDetector.push_back(pDetector);
                       }
                       while(1)
                       {
                           TriLine = mxmlGetNextSibling(TriLine);
                           if(!TriLine)
                               break;
                           qDebug() << "Element---" << mxmlGetElement(TriLine);
                           QString strTmp(mxmlGetElement(TriLine));
                           strTmp = strTmp.trimmed();
                           if(!(strTmp.compare(QString("TriLine").trimmed()) == 0))
                               continue;
                           //qDebug() << "Element---" << mxmlGetElement(TriLine);
                           if(mxmlGetType(TriLine) == 0)
                           {
                               //strNode = node->child->value.text.string;
                               node = mxmlFindElement(TriLine, tree, "point", NULL, NULL, MXML_DESCEND);
                               Detector*  pDetector = new Detector;
                               qDebug() << "TriLine  2";
                               if(node)
                               {
                                   QString strNode = node->child->value.opaque;
                                   qDebug() << strNode;
                                   QPoint pt = StrUtils::SplitStrToPt(strNode, ' ');
                                   qDebug() << pt.x() << "-- == "<< pt.y();
                                   pDetector->PushPoint(pt);
                                   while(1)
                                   {
                                       node = mxmlGetNextSibling(node);
                                       if(!node)
                                           break;
                                       if(mxmlGetType(node) == 0)
                                       {
                                           strNode = node->child->value.opaque;
                                           qDebug() << strNode;
                                           QPoint pt = StrUtils::SplitStrToPt(strNode, ' ');
                                           qDebug() << pt.x() << "-- == "<< pt.y();
                                           pDetector->PushPoint(pt);
                                       }
                                   }
                                   pDetector->SetType(nTriLine);
                                   m_arrDetector.push_back(pDetector);
                               }
                           }
                       }
                   }
               }
           }
           mxmlDelete(tree);
           qDebug() << "close OK";
       }
}

const char *whitespace_cb(mxml_node_t *node, int where)
{
    if ( where==MXML_WS_BEFORE_OPEN /*|| where == MXML_WS_AFTER_CLOSE*/ )
        return ("\n");
    else
        return NULL;
}

ImageData* XMLManager::GetImageData()
{
    return m_pImageData;
}

int XMLManager::SaveXML(QString strXMLPath)
{
    if(m_arrDetector.size() <= 0)
    {
        QFile file(strXMLPath);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) //以文本文式写入
        {
            QTextStream out(&file);
            file.close();
        }
        return 0;
    }
    mxml_node_t *tree, *ImageDetect, *ImageSrc,
            *Detect, *DetectArea, *TriLine, *ImagePath, *node;

    tree = mxmlNewXML("1.0");
    char chText[100];
    char chBuf[200000];
    if (tree != NULL)
    {
        ImageDetect = mxmlNewElement(tree, "ImageDetect");
        if(ImageDetect != NULL)
            ImageSrc = mxmlNewElement(ImageDetect, "ImageSrc");
        if(ImageSrc != NULL)
        {
            node = mxmlNewElement(ImageSrc, "Width");
            sprintf(chText, "%d", m_pImageData->nWidth);
            mxmlNewText(node, 0, chText);
            node = mxmlNewElement(ImageSrc, "Height");
            sprintf(chText, "%d", m_pImageData->nHeight);
            mxmlNewText(node, 0, chText);
        }

        if(ImageDetect != NULL)
            Detect = mxmlNewElement(ImageDetect, "Detect");

        if (Detect != NULL)
        {
            std::vector<Detector*>::iterator iterDetector = m_arrDetector.begin();
            for(; iterDetector != m_arrDetector.end(); iterDetector++)
            {
                std::vector<QPoint> arrPoints;
                if((*iterDetector)->GetType() == nDetArea)
                {
                    (*iterDetector)->GetPoints(arrPoints);
                    DetectArea = mxmlNewElement(Detect, "DetectArea");
                    if(DetectArea != NULL)
                    {
                        foreach (QPoint pt, arrPoints)
                        {
                            node = mxmlNewElement(DetectArea, "point");
                            sprintf(chText, "x=%d y=%d", pt.x(), pt.y());
                            mxmlNewText(node, 0, chText);
                        }
                    }
                }
                else if((*iterDetector)->GetType() == nTriLine)
                {
                    (*iterDetector)->GetPoints(arrPoints);
                    TriLine = mxmlNewElement(Detect, "TriLine");
                    if(TriLine != NULL)
                    {
                        foreach (QPoint pt, arrPoints)
                        {
                            node = mxmlNewElement(TriLine, "point");
                            sprintf(chText, "x=%d y=%d", pt.x(), pt.y());
                            mxmlNewText(node, 0, chText);
                        }
                    }
                }
            }
            if(ImageDetect != NULL)
            {
                ImagePath = mxmlNewElement(ImageDetect, "ImagePath");
                mxmlNewText(ImagePath, 0, m_pImageData->strImagePath.toStdString().data());
            }
       }
    }

    //直接存文件
#if 0
    FILE * fp = fopen(strXMLPath.toStdString().data(), "wt");
    if(fp != NULL)
    {
        mxmlSaveFile(tree, fp, whitespace_cb);
        if(fp != NULL)
        {
            fclose(fp);
            fp = NULL;
        }
    }
#endif

#if 1
    mxmlSaveString(tree, chBuf, 20000, whitespace_cb);
    QFile file(strXMLPath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) //以文本文式写入
    {
        QTextStream out(&file);
        out << chBuf << endl;
        file.close();
    }

#endif
    mxmlDelete(tree);
    return 0;
}

int XMLManager::SetDetectorData(const std::vector<Detector *> arrDetector)
{
    m_arrDetector = arrDetector;
    return m_arrDetector.size();
}

int XMLManager::GetDetectorData(std::vector<Detector *> &arrDetector)
{
    arrDetector = m_arrDetector;
    return arrDetector.size();
}

void XMLManager::SetImageData(ImageData *pImgData)
{
    //m_pImageData = pImgData;
    m_pImageData->nHeight = pImgData->nHeight;
    m_pImageData->nWidth = pImgData->nWidth;
    m_pImageData->strImagePath = pImgData->strImagePath;
}

void XMLManager::GetImageData(ImageData *pImgData)
{
    pImgData = m_pImageData;
}
