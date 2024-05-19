#pragma once

#include "ui_CarFleet.h"
#include "CarView.h"

class CarFleet : public QMainWindow
{
    Q_OBJECT

public:
    CarFleet(QWidget *parent = nullptr);
    ~CarFleet();

private slots:
    void onItemDoubleClicked(QListWidgetItem* item);
    void onAddButtonClicked();
    void receiveCar(const std::vector<std::string> *car);
    void receiveEraseIndex(const int index);

private:
    Ui::CarFleetClass ui;
    CarView *carView;
    std::vector<std::vector<std::string>>cars;

    void updateListWidget();
};
