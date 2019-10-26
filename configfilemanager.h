#ifndef CONFIGFILEMANAGER_H
#define CONFIGFILEMANAGER_H

#include <QString>
/*
    用于记录最新的xml文件路径和Jpg文件路径
*/
class ConfigFileManager
{
public:
    ConfigFileManager();

private:
    QString m_strXmlPath;
    QString m_strJpgPath;
    QString m_strIniPath;

private:
    int InitConfig();

public:
    void SetXmlPath(QString strXmlPath);
    void SetJpgPath(QString strJpgPath);
    QString GetXmlPath();
    QString GetJpgPath();
    void SaveConfigFile();
};

#endif // CONFIGFILEMANAGER_H
