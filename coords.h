#ifndef COORDS_H
#define COORDS_H

#include <QWidget>

namespace Ui {
class Coords;
}

class Coords : public QWidget
{
    Q_OBJECT

public:
    explicit Coords(QWidget *parent = nullptr);
    ~Coords();

private:
    Ui::Coords *ui;

private slots:
    void math();
};

#endif // COORDS_H
