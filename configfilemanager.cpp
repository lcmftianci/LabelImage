#include "configfilemanager.h"

#include <QStandardPaths>
#include <QStringList>
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

//初始化
ConfigFileManager::ConfigFileManager():m_strIniPath(""),m_strJpgPath(""),m_strXmlPath("")
{
    InitConfig();
}

/*
 *初始化，读取配置文件
 * 如果没有配置文件就默认读取程序所在路径
 */
int ConfigFileManager::InitConfig()
{
    //QString strIniPath = QFileDialog::getOpenFileName(this, tr("Open Config File"), "/home/long", tr("Ini Files (*.ini)"));
    //QStringList strFileList = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    m_strIniPath = QCoreApplication::applicationDirPath();
    if(m_strIniPath == "")
         return 0;
    QString strTmp = m_strIniPath;
    m_strIniPath += "/config.ini";
    QFile file(m_strIniPath);
    //char chBuf[2000];
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) //以文本文式写入
    {
        //strcpy(chBuf, file.readAll().toStdString().data());
        m_strXmlPath = file.readAll();
       if(!m_strXmlPath.isEmpty())
       {
            QFileInfo fi;
            fi = QFileInfo(m_strXmlPath);
            //file_name = fi.fileName();  //获取文件名
            m_strXmlPath = fi.absolutePath(); //获取文件路径(不包含文件名)
       }
       else
            m_strXmlPath = strTmp;
       file.close();
    }
}

/*
    设置xml文件路径
*/
void ConfigFileManager::SetXmlPath(QString strXmlPath)
{
    m_strXmlPath = strXmlPath;
}

/*
    设置图片文件路径
*/
void ConfigFileManager::SetJpgPath(QString strJpgPath)
{
    m_strJpgPath = strJpgPath;
}

/*
    获取xml文件路径
*/
QString ConfigFileManager::GetXmlPath()
{
    return m_strXmlPath;
}

/*
    获取jps文件路径
*/
QString ConfigFileManager::GetJpgPath()
{
    return m_strJpgPath;
}

void ConfigFileManager::SaveConfigFile()
{
    QFile file(m_strIniPath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) //以文本文式写入
    {
        QTextStream out(&file);
        out << m_strXmlPath.toStdString().data() << endl;
        file.close();
    }
}
