#pragma once

#include <QMainWindow>
#include "ui_CarView.h"
#include <CarBase.h>

enum WindowMode {
	VIEW,
	EDIT,
	ADD
};

class CarView : public QMainWindow
{
	Q_OBJECT

public:
	CarView(QWidget *parent = nullptr);
	~CarView();

	void setData(WindowMode mode, CarBase *car = nullptr, const int index = NULL);

signals:
	void sendCar(CarBase *data);
	void sendEraseIndex(const int index);

private slots:
	void onTypeChanged(int index);
	void onEditButtonClicked();
	void onDeleteButtonClicked();

private:
	Ui::CarViewClass ui;
	WindowMode mode;
	CarBase *car;
	int index;

	void setFormReadOnly();
};
