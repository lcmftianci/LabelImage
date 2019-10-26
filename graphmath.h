#ifndef GRAPHMATH_H
#define GRAPHMATH_H


/*
函数说明
double sin(double x)
x 的正弦函数值
double cos(double x)
x 的余弦函数值
double tan(double x)
x 的正切函数值
double asin(double x)
x 的反正弦函数值 sin-1x，x的值在 [-1,1] 之间，传回的值在 [-p/2,p/2] 之间
double acos(double x)
x 的反余弦函数值cos-1x，x的值在 [-1,1] 之间，传回的值在 [-p/2,p/2] 之间
double atan(double x)
x 的反正切函数值tan-1x，传回的值在 [-p/2,p/2] 之间
double atan2(double y, double x)
y/x 的反正切函数值tan-1(y/x)，传回的值在 [-p, p] 之间
double sinh(double x)
x 的双曲正弦函数值
double cosh(double x)
x 的双曲余弦函数值
double tanh(double x)
x 的双曲正切函数值
double exp(double x)
x 的指数函数 ex
double log(double x)
x 的自然对数 ln(x)，x > 0
double log10(double x)
x 底数为 10 的对数，log10x，x > 0
double pow(double x, double y)
x 的 y 次方 xy
double sqrt(double x)
x 的根号值 √x
double ceil(double x)
不小于 x 的最小整数（但其型别为 double）
double floor(double x)
不大于 x 的最大整数（但其型别为 double）
int abs(int x)
整数 x 的绝对值 |x|
long labs(long x)
长整数 x 的绝对值 |x|
double fabs(double x)
实数 x 的绝对值 |x|
*/

#include <QPoint>
#include <vector>

void GetRectagle(QPoint pt1, QPoint pt2, std::vector<QPoint>& arrPoint);

#endif // GRAPHMATH_H
