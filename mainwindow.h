#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QToolButton>
#include <QStyle>
#include <detector.h>
#include <common.h>
#include <xmlmanager.h>
#include <QRadioButton>
#include <QButtonGroup>
#include <QTimer>
#include "custommessagebox.h"
#include "configfilemanager.h"

//管理xml文件类
#include "xmlmanager.h"

class QString;
class QToolBar;
class QIcon;
class QPixmap;
class QPoint;
class QPainter;
class QCheckBox;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void InitView();
    void InitToolBar();
    void UpdatePen();
    void InitRedioGroup();
    int  DelPoint();
    int  DrawBitmap(int x, int y);
    int  PaintBitmap();
    int  DrawPoint();
    void ChangePix(bool bIn);   //图片分辨率转换
    void ReSortData(int nIndex);          //重新排序
    void AnimationShow();

private slots:
    void LoadImage();
    void ResetView();
    void OnLoadData();
    void OnSaveData();
    void OnShowStyle();
    void OnSetWidth(int nWidth);
    void OnSetColor();
    void OnRadioChecked(QAbstractButton* aBtn);
    void OnTimeSlot();
    void OnReTry();
    void OnSelectType(int nType);

protected:
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent* event);

private:
    QString    m_strFilePath;
    QString    m_strXmlPath;
    QIcon      m_icon;
    QPixmap    m_pix;
    QPoint     m_oldPt;
    QPoint     m_pt;
    QColor     m_color;
    QPixmap    m_realPix;
    QPoint     m_LabelPos;
    QPoint     m_GlobalOldPos;
    QPoint     m_GlobalPos;
    int        m_xOffSet;       //图片偏移量
    int        m_yOffSet;
    int        m_xPropertion;   //Label与图片X方向上的压缩比例
    int        m_yPropertion;   //Label与图片Y方向上的压缩比例
    int        m_xOldPropertion;//Label与图片Y方向上的压缩比例原始
    int        m_yOldPropertion;//Label与图片Y方向上的压缩比例原始
    int        m_nPixWidth;     //原始图片宽度
    int        m_nPixHeight;    //原始图片高度
    int        m_nRealWidth;    //label显示出来的实际图片宽度
    int        m_nRealHeight;   //label显示出来的实际图片高度
    int        m_style;
    int        m_wigth;

    int        m_AreaNum;
    int        m_nCurDetector;  //移动哪一个检测器
    int        m_nCurLine;      //当前是哪一条线
    int        m_nCurPoint;     //当前是哪一点
    int        m_nCurPt;        //当前点

    int        m_nCurType;      //当前选中的类型
    int        m_nPreType;      //前一个选中的类型，通过类型判断是否创建新的detector
    bool       m_bBegin;        //起始点
    bool       m_bCanMoveView;    //是否可以移动数据
    bool       m_bCanMovePoint;   //移动点
    int        m_nPointIndex;     //移动额第几个点
    bool       m_bClick;          //用户是否点击鼠标
    int        m_nReEdit;         //再次可编辑状态
    bool       m_bDoubleClick;    //是否双击


    QPoint     m_qCurPt;        //上次鼠标点击的位置
    QPoint     m_qCurGlobal;    //上次鼠标点击的全局坐标
    QPoint     m_qPreGlobal;    //鼠标移动钱的一个坐标

    Ui::MainWindow *ui;
    QPixmap  * m_pPix;
    QPainter * m_painter;
    QToolBar * m_pToolBar;
    QLabel   * m_pStyleLabel;
    QComboBox * m_pStyleComboBox;
    QLabel    * m_pWidthLabel;
    QSpinBox  * m_pWidthSpinBox;
    QLabel    * m_pColorLabel;
    QToolButton * m_pColorBtn;
    QButtonGroup* m_pBtnGroup;
    QRadioButton* m_pRadioArea;
    QRadioButton* m_pRadioTriLine;
    QRadioButton* m_pRadioComplete;
    QCheckBox   * m_pCheckComplete;
    QTimer      * m_pTimer;
    XMLManager  * m_pXmlManager;
    CustomMessageBox *m_pMsgBox;
    ConfigFileManager *m_pConfigFileManager;

    std::vector<Detector*> m_arrDetector;   //所有检测类
};

#endif // MAINWINDOW_H
