#include "custommessagebox.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextCodec>
#include <QObject>
#include <QDebug>


#define LAYOUT_SPACING 20
#define DEFAULT_HEIGHT  (300)
#define DEFAULT_WIDTH   (350)
#define MIN_WEIGHT      (150)
#define MIN_WIDTH       (150)
#define FONT_SIZE       (14)


CustomMessageBox::CustomMessageBox(CustomMessageBox::CUSTOM_MESSAGE_TYPE type,
       const QString &strTitle, const QString &strInfo, QWidget *parent,
       Qt::WindowFlags flags):QDialog(parent, flags), m_eCustomType(type)
{
    initialize(strInfo);
    alignment();
    setWindowTitle(strTitle);
    resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setMinimumSize(MIN_WIDTH, MIN_WEIGHT);
}

CustomMessageBox::~CustomMessageBox()
{

}

//设置标签的内容
void CustomMessageBox::setTextInfo(const QString &strInfo)
{
#if 0
    if(!strInfo.isEmpty())
        m_pLabelInfo->setText(strInfo);
#endif
}

void CustomMessageBox::setTextInfo(const QString &strTitle, const QString &strInfo)
{
#if 0
    if(strTitle.isEmpty())
        this->setWindowTitle(strTitle);

    if(!strInfo.isEmpty())
        m_pLabelInfo->setText(strInfo);
#endif
}

void CustomMessageBox::setTextInfo(CUSTOM_MESSAGE_TYPE type, const QString &strTitle, const QString &strInfo)
{
#if 0
    if(strTitle.isEmpty())
        this->setWindowTitle(strTitle);

    if(!strInfo.isEmpty())
        m_pLabelInfo->setText(strInfo);
    else
        return ;

     m_eCustomType = type;
     QString fileName;
     switch(m_eCustomType){
     case CUSTOM_MESSAGE_QUESTION:
         fileName = ":/question";
         break;
     case CUSTOM_MESSAGE_INFORMATION:
         fileName = ":/information";
         break;
     case CUSTOM_MESSAGE_WARNING:
         fileName = ":/warning";
         break;
     case CUSTOM_MESSAGE_CRITICAL:
         fileName = ":/error";
         break;
     default:
         break;
     }
     QPixmap iconPix(fileName);
     m_pLabelIcon->setPixmap(iconPix);
#endif
}


void CustomMessageBox::initialize(const QString &strInfo)
{
#if 0
    m_pLabelIcon = new QLabel(this);
    QString fileName;
    switch(m_eCustomType){
    case CUSTOM_MESSAGE_QUESTION:
        fileName = ":/question";
        break;
    case CUSTOM_MESSAGE_INFORMATION:
        fileName = ":/information";
        break;
    case CUSTOM_MESSAGE_WARNING:
        fileName = ":/warning";
        break;
    case CUSTOM_MESSAGE_CRITICAL:
        fileName = ":/error";
        break;
    default:
        break;
    }

    QPixmap iconPix(fileName);
    m_pLabelIcon->setPixmap(iconPix);
    m_pLabelIcon->setFixedSize(45,45);
    m_pLabelIcon->setObjectName("msgBoxIconLabel");

    QFont font;
    font.setBold(true);
    font.setFamily("Consolas");
    font.setPixelSize(FONT_SIZE);

    m_pLabelInfo = new QLabel(strInfo, this);
    m_pLabelInfo->setWordWrap(true);
        m_pLabelInfo->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        m_pLabelInfo->setFont(font);
    m_pLabelInfo->setObjectName("msgBoxInfoLabel");


    m_pBtnYes = new QToolButton(this);
    QPixmap yesPix(":/yes_Btn");
    m_pBtnYes->setIcon(yesPix);
    m_pBtnYes->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_pBtnYes->setIconSize(QSize(30, 30));
    m_pBtnYes->setFont(font);
    m_pBtnYes->setObjectName("msgBoxYesBtn");
    m_pBtnYes->setFocusPolicy(Qt::NoFocus);

    if(m_eCustomType == CUSTOM_MESSAGE_QUESTION)
        m_pBtnYes->setText(tr("Yes"));
    else
        m_pBtnYes->setText(tr("Ok"));

    connect(m_pBtnYes, SIGNAL(released()), this, SLOT(accept()));

    if(m_eCustomType == CUSTOM_MESSAGE_QUESTION)
    {
        m_pBtnNo = new QToolButton(this);
        QPixmap noPix(":/no_Btn");
        m_pBtnNo->setIcon(noPix);
        m_pBtnNo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        m_pBtnNo->setIconSize(QSize(30, 30));
        m_pBtnNo->setText(tr("No") );
        m_pBtnNo->setFont(font);
        m_pBtnNo->setObjectName("msgBoxNoBtn");
        m_pBtnNo->setFocusPolicy(Qt::NoFocus);

        connect(m_pBtnNo, SIGNAL(released()), this, SLOT(reject()));
    }

#endif
    QTextCodec *pCoder = QTextCodec::codecForName("gb2312");

    Qt::WindowFlags flags=Qt::Dialog;
//    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    m_pArea = new QPushButton(this);
    m_pArea->setText(pCoder->toUnicode("检测区域"));
    QObject::connect(m_pArea, SIGNAL(clicked(bool)), this, SLOT(OnSelectDecArea(bool)));

    m_pLine = new QPushButton(this);
    m_pLine->setText(pCoder->toUnicode("报警线"));
    QObject::connect(m_pLine, SIGNAL(clicked(bool)), this, SLOT(OnSelectTriLine(bool)));

    m_pEdit = new QPushButton(this);
    m_pEdit->setText(pCoder->toUnicode("编辑状态"));
    QObject::connect(m_pEdit, SIGNAL(clicked(bool)), this, SLOT(OnSelectEdit(bool)));
}
//界面布局
void CustomMessageBox::alignment()
{
    //布局管理
    QVBoxLayout *pVB = new QVBoxLayout;
    pVB->setSpacing(20);
    pVB->addWidget(m_pArea);
    pVB->addWidget(m_pLine);
    pVB->addWidget(m_pEdit);
    this->setLayout(pVB);

#if 0
    QHBoxLayout *hbLabelLayout = new QHBoxLayout;
    hbLabelLayout->addWidget(m_pLabelIcon);
    hbLabelLayout->addWidget(m_pLabelInfo);

    QHBoxLayout *hbBtnLayout = new QHBoxLayout;
    hbBtnLayout->addStretch();
    hbBtnLayout->addWidget(m_pBtnYes);
    if(m_eCustomType == CUSTOM_MESSAGE_QUESTION){
        hbBtnLayout->addStretch();
        hbBtnLayout->addWidget(m_pBtnNo);
    }
    hbBtnLayout->addStretch();

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->addLayout(hbLabelLayout);
    vbLayout->addSpacing(20);
    vbLayout->addLayout(hbBtnLayout);

    this->setLayout(vbLayout);
#endif
}

void CustomMessageBox::OnSelectDecArea(bool bClick)
{
    qDebug() << "Area";
    SendCurType(0);
    close();
    //connect(m_pArea, SIGNAL(released()), this, SLOT(accept()));
}

void CustomMessageBox::OnSelectTriLine(bool bClick)
{
    qDebug() << "Line";
    SendCurType(1);
     close();
    //connect(m_pLine, SIGNAL(released()), this, SLOT(accept()));
}

void CustomMessageBox::OnSelectEdit(bool bClick)
{
    qDebug() << "Edit";
    SendCurType(2);
    close();
    //connect(m_pEdit, SIGNAL(released()), this, SLOT(accept()));
}
