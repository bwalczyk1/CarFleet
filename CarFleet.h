#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CarFleet.h"

class CarFleet : public QMainWindow
{
    Q_OBJECT

public:
    CarFleet(QWidget *parent = nullptr);
    ~CarFleet();

private:
    Ui::CarFleetClass ui;
};
