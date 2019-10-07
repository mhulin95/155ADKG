#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QPoint>

class algorithms
{
public:
    algorithms();
    static int getPointLinePosition(QPoint &q,QPoint &p1,QPoint &p2);
    static double getAngle2Vectors(QPoint &p1,QPoint &p2,QPoint &p3,QPoint &p4);
};

#endif // ALGORITHMS_H
