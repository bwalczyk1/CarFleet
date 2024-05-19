#pragma once

#include <QMainWindow>
#include "ui_CarView.h"
#include <string>
#include <vector>

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

	void setData(WindowMode mode, std::vector<std::string> *car = nullptr, const int index = NULL);

signals:
	void sendCar(const std::vector<std::string> *data);
	void sendEraseIndex(const int index);

private slots:
	void onEditButtonClicked();
	void onDeleteButtonClicked();

private:
	Ui::CarViewClass ui;
	WindowMode mode;
	std::vector<std::string> *car;
	int index;

	void setFormReadOnly(bool readOnly);
};
