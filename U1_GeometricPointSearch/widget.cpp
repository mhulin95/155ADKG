#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"

#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    ui->Canvas->clearPoints();
    ui->label->clear();
}

void Widget::on_pushButton_3_clicked()
{
    ui->Canvas->setDrawMode();
}

void Widget::on_pushButton_4_clicked()
{
    //Analyze point and polygon position
    QPoint q = ui->Canvas->getPoint();
    std::vector<QPoint> polygon = ui->Canvas->getPolygon();

    //Select method
    int res = 0;
    if (ui->comboBox->currentIndex() == 0)
        res = Algorithms::positionPointPolygonWinding(q, polygon);
    else
        res = Algorithms::positionPointPolygonRayCrossing(q, polygon);

    //Print results
    if (res == 1)
        ui->label->setText("Inside");
    else
        ui->label->setText("Outside");
}

void Widget::on_pushButton_import_polygon_clicked()
{
    ui->Canvas->importPolygon();

}
