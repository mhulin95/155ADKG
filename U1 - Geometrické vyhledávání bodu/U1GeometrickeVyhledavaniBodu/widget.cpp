#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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
    ui->Canvas->clearPoints();
}

void Widget::on_pushButton_draw_clicked()
{
    ui->Canvas->setDrawMode();
}

void Widget::on_removeLastButton_clicked()
{
    ui->Canvas->removeLastPoints();
}

void Widget::on_pushButton_import_polygon_clicked()
{
    //Select text file with polygon coordinates
    QString polygonFilePath = QFileDialog::getOpenFileName(this, "Import polygon", "C://", "Text file (*.txt)");

    QFile file_import(polygonFilePath);

    //Check if the file was opened correctly
    if(!file_import.open(QFile::ReadOnly)){
        QMessageBox::warning(this, "Opening error!", "File can not be open");
    }
    QTextStream in(&file_import);
    QString import_body_polygon = in.readAll();
    ui->plainTextEdit->setPlainText(import_body_polygon);

    file_import.close();

}
