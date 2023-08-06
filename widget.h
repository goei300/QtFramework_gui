#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    int moneyUnit[4]={500,100,50,10};
    int moneyRemain[4]={0,0,0,0};
    void updateButtonStatus();
    void changeMoney(int diff);
    void anyone();
    QString strReturn();

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pbCup_clicked();

    void on_pbTea_clicked();

    void on_pbMilk_clicked();

    void on_pbRet_clicked();

    void on_pb500_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
