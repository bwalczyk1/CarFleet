#pragma once
#include "CarBase.h"
class PassengerCar : public CarBase {
private:
	int seats;
public:
	PassengerCar() : CarBase(), seats( 0 ) {};
	PassengerCar( std::string brandArg, std::string modelArg, int productionYearArg, std::string licenseNumberArg, float massArg, int seatsArg ) : CarBase( brandArg, modelArg, productionYearArg, licenseNumberArg, massArg ), seats( seatsArg ) {};
	PassengerCar( const PassengerCar &carArg );

	std::string getInfo();
	int getSeats();
	void setSeats( int newSeats );
};

