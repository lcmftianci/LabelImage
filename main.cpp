#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QDial>
#include <QDir>
#include <QFile>
#include <QIODevice>

//load stylesheet
void loadStyleSheet(QString strPath)
{
    //设置编码格式
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QFile file(strPath);
    file.open(QIODevice::ReadOnly);
    QString cstyle = file.readAll();
    qApp->setStyleSheet(cstyle);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << QDir::currentPath();
    QString strExePath = QCoreApplication::applicationDirPath();
    strExePath += "/stylesheet/newBlack.css";
    loadStyleSheet(strExePath);

    MainWindow w;
    w.show();

    return a.exec();
}
