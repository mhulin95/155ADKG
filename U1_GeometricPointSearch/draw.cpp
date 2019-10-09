#include "draw.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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
        polygon.push_back(p);
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
    for (int i = 0; i < polygon.size(); i++)
    {
        qp.drawEllipse(polygon[i].x() - r/2,polygon[i].y() - r/2, r, r);
    }

    //Draw  polygon
    QPolygon qpoly;
    for(int i = 0;i < polygon.size(); i++)
    {
        qpoly.append(polygon[i]);
    }

    qp.drawPolygon(qpoly);


    qp.end();
}

void Draw::clearPoints()
{
      polygon.clear();
      q.setX(-100);
      q.setY(-100);
      repaint();
}

void Draw::importPolygon()
{
    // Select text file with polygons coordinates
    QFile file(QFileDialog::getOpenFileName(this, "Select text file with the polygons", "C://", "Text file (*.txt)"));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
/*
    //Check if the file is opened
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::warning(this, "Error", "File can not be open");
     !!! Doesn´t work as expected, shows fault in correct case
*/

    //Display content of the text file
    QTextStream stream(&file);
    QString text = stream.readAll();
    QMessageBox box;
    box.setText(text);
    box.exec();

    file.close();

}
