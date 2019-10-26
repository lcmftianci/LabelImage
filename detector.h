#ifndef DETECTOR_H
#define DETECTOR_H

#include <QPoint>
#include <vector>
#include <iostream>
#include <QColor>
#include "common.h"

class Detector
{
public:
    Detector();

    void PushPoint(QPoint pt);
    void ReplacePoint(QPoint pt, int index = 0);
    int GetPoints(std::vector<QPoint>& arrPoints);
    void PushPoint(const std::vector<QPoint>& arrPoints);
    QColor GetColor();
    void SetColor(QColor color);
    int GetPointSize(){return m_arrPoint.size();}
    QPoint GetLastPoint();
    void DeletePoint();
    void SetWidth(int nWidth);
    int GetWidth();

    //处理用户点击移动等操作
    int IsSamePoint(QPoint pt);    //用户是否选择了一个队列当中的点，如果是就允许调用移动点功能
    void MovePoint(QPoint pt, int index);     //移动点就是点的替换
    void MoveView(int x, int y);   //整个区域的移动
    bool IsInArea(QPoint pt);      //用户选择点是否在当前闭合区域内
    bool IsInArea(QPoint pt, const std::vector<QPoint> arrPoint);
    bool IsInLine(QPoint pt);      //选线
    bool IsInLine(QPoint pt, QPoint pt1, QPoint pt2);  //选线

private:
    std::vector<QPoint> m_arrPoint;
   // int m_nType;          //检测器类型

    int m_nPenWidth;        //画笔宽度
    int m_nPenStyle;        //画笔类型
    QColor m_cColor;           //画笔颜色


    GS(DetectType, Type)           //检测器类型
};

#endif // DETECTOR_H
