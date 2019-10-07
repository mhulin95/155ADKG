#include "draw.h"
#include <fstream>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    //Initialization
    draw_mode = true; // true = polygon, false = point

    q.setX(-100);
    q.setY(-100);

}

void Draw::mousePressEvent(QMouseEvent *e)
{
    //Get coordinates od the mouse
    int x = e->x();
    int y = e->y();

    //Add points to polygon
    if (draw_mode)
    {
        //Create new point
        QPoint p(x,y);

        //Add point to the list
        points.push_back(p);
    }

    //Set coordinate of q
    else {
       q.setX(x);
       q.setY(y);
    }

    repaint();
}

void Draw::paintEvent(QPaintEvent *e)
{
    QPainter qp(this);
    qp.begin(this);
    int r = 5;
    int r2 = 10;

    //Draw point Q
    qp.drawEllipse(q.x() - r2/2,q.y() - r2/2, r2, r2);

    //Draw all points
    for (int i = 0; i < points.size(); i++)
    {
        qp.drawEllipse(points[i].x() - r/2,points[i].y() - r/2, r, r);
    }

    //Draw  polygon
    QPolygon qpoly;
    for(int i = 0;i < points.size(); i++)
    {
        qpoly.append(points[i]);
    }

    qp.drawPolygon(qpoly);


    qp.end();
}

void Draw::clearPoints()
{
      points.clear();
      q.setX(-100);
      q.setY(-100);
      repaint();
}

void Draw::removeLastPoints()
{
      points.pop_back();
      repaint();
}

void Draw::import_polygons(char polygonFilePath,std::fstream polygonFileName)
{

}
