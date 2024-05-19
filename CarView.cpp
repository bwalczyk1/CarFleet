#include "CarView.h"
#include <vector>

CarView::CarView(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    mode = VIEW;
    car = nullptr;
    index = NULL;

    connect(ui.deleteButton, &QPushButton::clicked, this, &CarView::onDeleteButtonClicked);
    connect(ui.editButton, &QPushButton::clicked, this, &CarView::onEditButtonClicked);
}

CarView::~CarView()
{
    if (mode == ADD) {
        delete this->car;
    }
}

void CarView::setData(WindowMode mode, std::vector<std::string> *car, const int index) {

    if (mode == VIEW || mode == ADD) {
        if (this->mode == ADD) {
            delete this->car;
        }

        if (mode == VIEW) {
            ui.deleteButton->show();

            this->car = car;
        } else {
            ui.deleteButton->hide();

            this->car = new std::vector<std::string>();
            this->car->push_back("");
            this->car->push_back("");
        }

        this->index = index;

        ui.brandLineEdit->setText(QString::fromStdString((*this->car)[0]));
        ui.modelLineEdit->setText(QString::fromStdString((*this->car)[1]));
    }

    setFormReadOnly(mode == VIEW);
    ui.editButton->setText(mode == VIEW ? "Edit" : "Save");

    this->mode = mode;
}

void CarView::setFormReadOnly(bool readOnly)
{
    for (int i = 0; i < ui.formLayout->rowCount(); ++i) {
        QLayoutItem* item = ui.formLayout->itemAt(i, QFormLayout::FieldRole);

        if (item) {
            QWidget* widget = item->widget();

            if (QLineEdit* lineEdit = qobject_cast<QLineEdit*>(widget)) {
                lineEdit->setReadOnly(readOnly);
            }
        }
    }
}

void CarView::onEditButtonClicked() {
    if (mode == VIEW) {
        this->setData(EDIT);

        return;
    }

    (*this->car)[0] = ui.brandLineEdit->text().toStdString();
    (*this->car)[1] = ui.modelLineEdit->text().toStdString();

    emit sendCar(mode == ADD ? this->car : nullptr);
}

void CarView::onDeleteButtonClicked() {
    emit sendEraseIndex(index);
}