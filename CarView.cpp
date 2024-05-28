#include "CarView.h"
#include "DeliveryCar.h"
#include "PassengerCar.h"
#include <vector>
#include <qmessagebox.h>

CarView::CarView(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
    onTypeChanged(0);
    mode = VIEW;
    car = nullptr;
    index = NULL;

    connect(ui.typeComboBox, &QComboBox::currentIndexChanged, this, &CarView::onTypeChanged);
    connect(ui.deleteButton, &QPushButton::clicked, this, &CarView::onDeleteButtonClicked);
    connect(ui.editButton, &QPushButton::clicked, this, &CarView::onEditButtonClicked);
}

CarView::~CarView()
{
}

void CarView::setData(WindowMode mode, CarBase *car, const int index) {
    if (mode == VIEW || mode == ADD) {
        ui.deleteButton->setHidden(mode != VIEW);

        ui.brandLineEdit->setText(QString::fromStdString(car ? car->getBrand() : ""));
        ui.modelLineEdit->setText(QString::fromStdString(car ? car->getModel() : ""));
        ui.yearSpinBox->setValue(car ? car->getProductionYear() : 2024);
        ui.licenceNumberLineEdit->setText(QString::fromStdString(car ? car->getLicenseNumber() : ""));
        ui.massDoubleSpinBox->setValue(car ? car->getMass() : 1200.0);

        PassengerCar* passengerCar = dynamic_cast<PassengerCar*>(car);
        DeliveryCar* deliveryCar = dynamic_cast<DeliveryCar*>(car);

        ui.typeComboBox->setCurrentIndex(car && deliveryCar);
        ui.seatsSpinBox->setValue(car && passengerCar ? passengerCar->getSeats() : 5);
        ui.maxMassDoubleSpinBox->setValue(car && deliveryCar ? deliveryCar->getMaxAuthorisedMass() : 3500.0);

        this->car = car;
        this->index = index;
    }

    ui.editButton->setText(mode == VIEW ? "Edytuj" : "Zapisz");
    this->mode = mode;
    setFormReadOnly();
}

void CarView::setFormReadOnly() {
    for (int i = 0; i < ui.formLayout->rowCount(); ++i) {
        QLayoutItem* item = ui.formLayout->itemAt(i, QFormLayout::FieldRole);

        if (!item) {
            continue;
        }

        QWidget* widget = item->widget();

        if (QLineEdit* lineEdit = qobject_cast<QLineEdit*>(widget)) {
            lineEdit->setReadOnly(mode == VIEW);
        } else if (QSpinBox* spinBox = qobject_cast<QSpinBox*>(widget)) {
            spinBox->setReadOnly(mode == VIEW);
        } else if (QDoubleSpinBox* doubleSpinBox = qobject_cast<QDoubleSpinBox*>(widget)) {
            doubleSpinBox->setReadOnly(mode == VIEW);
        } else if (QComboBox* comboBox = qobject_cast<QComboBox*>(widget)) {
            comboBox->setEnabled(mode == ADD);
        }
    }
}

void CarView::onTypeChanged(int index) {
    ui.seatsLabel->setHidden(index);
    ui.seatsSpinBox->setHidden(index);
    ui.maxMassLabel->setHidden(!index);
    ui.maxMassDoubleSpinBox->setHidden(!index);
}

void CarView::onEditButtonClicked() {
    if (mode == VIEW) {
        this->setData(EDIT);

        return;
    }

    if (ui.typeComboBox->currentIndex() && ui.maxMassDoubleSpinBox->value() < ui.massDoubleSpinBox->value()) {
        QMessageBox::information(nullptr, "B³êdne dane", "DMC nie mo¿e byæ mniejsze niŸ masa pojazdu.");

        return;
    }

    if (mode == ADD) {
        if (ui.typeComboBox->currentIndex()) {
            car = new DeliveryCar();
        } else {
            car = new PassengerCar();
        }
    }

    car->setBrand(ui.brandLineEdit->text().toStdString());
    car->setModel(ui.modelLineEdit->text().toStdString());
    car->setProductionYear(ui.yearSpinBox->value());
    car->setLicenseNumber(ui.licenceNumberLineEdit->text().toStdString());
    car->setMass(ui.massDoubleSpinBox->value());

    if (ui.typeComboBox->currentIndex()) {
        DeliveryCar* deliveryCar = dynamic_cast<DeliveryCar*>(car);
        deliveryCar->setMaxAuthorisedMass(ui.maxMassDoubleSpinBox->value());
    } else {
        PassengerCar* passengerCar = dynamic_cast<PassengerCar*>(car);
        passengerCar->setSeats(ui.seatsSpinBox->value());
    }

    emit sendCar(mode == ADD ? car : nullptr);
}

void CarView::onDeleteButtonClicked() {
    emit sendEraseIndex(index);
}