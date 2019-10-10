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


void Widget::on_clearButton_clicked()
{
    ui->Canvas->clearCanvas();
    ui->label->clear();
}

void Widget::on_drawModeButton_clicked()
{
    ui->Canvas->setDrawMode();
}

void Widget::on_analyzeButton_clicked()
{
    //Analyze point and polygon position
    QPoint q = ui->Canvas->getPoint();
    std::vector<QPoint> polygon = ui->Canvas->getPolygon(0);

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

void Widget::on_importPolygonButton_clicked()
{
    //Select text file with polygons coordinates
    QString source_file = QFileDialog::getOpenFileName(this, "Select text file with the polygons", "C://", "Text file (*.txt)");

    //Convert path from QString to string
    std::string source_file_std = source_file.toStdString();

    //Load polygons
    ui->Canvas->importPolygon(source_file_std);
}
