#include "graphmath.h"

#include <math.h>
#include <QDebug>

void GetRectagle(QPoint pt1, QPoint pt2, std::vector<QPoint>& arrPoint)
{
    qDebug() << pt1.y() << " - " << pt2.y() << " - " << pt1.x() << " - " << pt2.x();
    if(pt1.y() != pt2.y())
    {
        double k = fabs((double)(pt1.x() - pt2.x())/(double)(pt1.y() - pt2.y()));
        qDebug() << "k" << k;
        double rat = fabs(atan(k));
         qDebug() << "rat" << rat;
        int x = fabs(5*cos(rat));
         qDebug() << "x" << x;
        int y = fabs(5*sin(rat));
         qDebug() << "y" << y;
        arrPoint.push_back(QPoint(pt1.x() + x, pt1.y() + y));
        arrPoint.push_back(QPoint(pt1.x() - x, pt1.y() - y));
        arrPoint.push_back(QPoint(pt2.x() - x, pt2.y() - y));
        arrPoint.push_back(QPoint(pt2.x() + x, pt2.y() + y));
    }

    if(pt1.x() == pt2.x() && pt1.y() == pt2.y())
        return;

    if(pt1.y() == pt2.y() && pt1.x() != pt2.x())
    {
        arrPoint.push_back(QPoint(pt1.x(), pt1.y() + 5));
        arrPoint.push_back(QPoint(pt1.x(), pt1.y() - 5));
        arrPoint.push_back(QPoint(pt2.x(), pt2.y() - 5));
        arrPoint.push_back(QPoint(pt2.x(), pt2.y() + 5));
    }
}
