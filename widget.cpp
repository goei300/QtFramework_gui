#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCup->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateButtonStatus()
{
    // money 변수의 값에 따라 버튼들의 활성화 여부를 결정합니다.
    if (money < 100) {
        ui->pbCup->setEnabled(false);
    } else {
        ui->pbCup->setEnabled(true);
    }

    if (money < 150) {
        ui->pbTea->setEnabled(false);
    } else {
        ui->pbTea->setEnabled(true);
    }

    if (money < 200) {
        ui->pbMilk->setEnabled(false);
    } else {
        ui->pbMilk->setEnabled(true);
    }
}

void Widget::changeMoney(int diff){
    money +=diff;
    ui->lcdNumber->display(money);
    updateButtonStatus();
}
void Widget::anyone(){
    int remain=money;
    int moneyRe[4]={0,0,0,0};
    for(int i=0;i<4;i++){
        while(remain>=moneyUnit[i]){
            moneyRe[i]++;
            remain -=moneyUnit[i];
        }
        moneyRemain[i]=moneyRe[i];
    }
}

QString Widget::strReturn(){
    QString str="";
    for(int i=0;i<4;i++){
        str+=QString("%1 WON:            %2\n").arg(moneyUnit[i]).arg(moneyRemain[i]);
    }
    return str;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}
void Widget::on_pbCup_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbRet_clicked()
{
    QMessageBox mb;
    anyone();
    mb.information(nullptr,"title",strReturn());
}



