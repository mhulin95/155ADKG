#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_clearButton_clicked();

    void on_drawModeButton_clicked();

    void on_analyzeButton_clicked();

    void on_importPolygonButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
