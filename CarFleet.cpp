#pragma warning(disable : 6387)

#include "CarFleet.h"
#include "FileUtils.h"
#include <qmessagebox.h>

CarFleet::CarFleet(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);
    
    try {
        FileUtils::readCarVector("cars.txt", cars);
    } catch (const std::invalid_argument &e) {
        QMessageBox::warning(nullptr, "Error", e.what());
    } catch (const std::exception& e) {
        QMessageBox::warning(nullptr, "Error", e.what());
    }

    updateListWidget();
    carView = new CarView();

    connect(ui.listWidget, &QListWidget::itemDoubleClicked, this, &CarFleet::onItemDoubleClicked);
    connect(ui.addButton, &QPushButton::clicked, this, &CarFleet::onAddButtonClicked);
    connect(carView, &CarView::sendCar, this, &CarFleet::receiveCar);
    connect(carView, &CarView::sendEraseIndex, this, &CarFleet::receiveEraseIndex);
}

CarFleet::~CarFleet() {
    try {
        FileUtils::writeCarVector("cars.txt", cars);
    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(nullptr, "Error", e.what());
    } catch (const std::exception& e) {
        QMessageBox::warning(nullptr, "Error", e.what());
    }

    for (int i = 0; i < cars.size(); i++) {
        delete cars[i];
    }
}

void CarFleet::onItemDoubleClicked(QListWidgetItem* item) {
    int index = ui.listWidget->row(item);

    carView->setData(VIEW, cars[index], index);
    carView->show();
    this->hide();
}

void CarFleet::onAddButtonClicked() {
    carView->setData(ADD);
    carView->show();
    this->hide();
}

void CarFleet::receiveCar(CarBase *data) {
    if (data != nullptr) {
        cars.push_back(data);
    }

    updateListWidget();
    carView->hide();
    this->show();
}

void CarFleet::receiveEraseIndex(const int index) {
    delete cars[index];
    cars.erase(std::next(cars.begin(), index));

    updateListWidget();
    carView->hide();
    this->show();
}

void CarFleet::updateListWidget() {
    ui.listWidget->clear();

    for (int i = 0; i < cars.size(); i++) {
        ui.listWidget->addItem(QString::fromStdString(cars[i]->getInfo()));
    }
}
