#include "CarFleet.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarFleet w;
    w.show();
    return a.exec();
}
