#include "coords.h"
#include "ui_coords.h"

Coords::Coords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Coords)
{
    ui->setupUi(this);

    connect(ui->pushButton_come_back, SIGNAL(clicked()), this, SLOT(math()));
}

Coords::~Coords()
{
    delete ui;
}

void Coords::math()
{
   // QWidget *main_ = new MainWindow();
   // main_->show();
   // hide();
}
