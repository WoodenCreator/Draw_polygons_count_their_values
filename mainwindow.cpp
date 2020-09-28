#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_main_, SIGNAL(clicked()), this, SLOT(count_points()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::count_points()
{
    int count;
    int num = 0;
    int i = 0; //шаг сдвига эдитов
    string error = "Put the correct value!";

    if ((ui->lineEdit_count->text() != "0") && (ui->lineEdit_count->text().toInt() != 0 && ui->lineEdit_count->text().toInt() > 0))
    {
        ui->label_Error->setText("");
        count = ui->lineEdit_count->text().toInt();
       //   Coords Window;
       //     Window.setModal(true);
       //     Window.exec();
       QWidget *Window = new Coords(); // Не добавлять This ни в коем случае, а то он накладывает одно окно на другое
       Window->show();
       hide(); //<- скрыть окно
       while (num < count)
       {
           QLineEdit* edit =  new QLineEdit("0", Window);  //        <- создание поля LineEdit для координат
           QLineEdit* edit2 =  new QLineEdit("0", Window);
           QLabel* number1 =  new QLabel(QString::number(num+1), Window);
           QLabel* number2 =  new QLabel(QString::number(num+1), Window);
           QRect geo_edit;
           QRect geo_edit2;
           geo_edit.setX(40);
           geo_edit.setY(90+i);
           geo_edit.setWidth(100); //Ширина второй кнопки
           geo_edit.setHeight(24);
           edit->setGeometry(geo_edit); //Задаём геометрию кнопке
           edit->show();
           geo_edit2.setX(220);
           geo_edit2.setY(90+i);
           geo_edit2.setWidth(100);
           geo_edit2.setHeight(24);
           edit2->setGeometry(geo_edit2);
           edit2->show();
           QRect geo_number1;
           QRect geo_number2;
           geo_number1.setX(20);
           geo_number1.setY(90+i);
           geo_number1.setWidth(24);
           geo_number1.setHeight(24);
           number1->setGeometry(geo_number1);
           number1->show();
           geo_number2.setX(200);
           geo_number2.setY(90+i);
           geo_number2.setWidth(24);
           geo_number2.setHeight(24);
           number2->setGeometry(geo_number2);
           number2->show();
       num++;
       i = i + 30;
       }

    }
    else
    {
        ui->label_Error->setText(QString::fromStdString(error));

    }
}


void MainWindow::on_pushButton_close_clicked()
{
    qApp->exit();
}
