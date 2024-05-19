#include "CarFleet.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CarFleet carFleet;
    carFleet.show();
    return app.exec();
}
