#pragma once
#include "CarBase.h"
class PassengerCar : public CarBase {
private:
	int seats;
public:
	static const std::string TYPE;

	PassengerCar() : CarBase(), seats( 0 ) {};
	PassengerCar( std::string brandArg, std::string modelArg, int productionYearArg, std::string licenseNumberArg,
		float massArg, int seatsArg ) : CarBase( brandArg, modelArg, productionYearArg, licenseNumberArg, massArg ), seats( seatsArg ) {};
	PassengerCar( const PassengerCar &carArg );

	std::string getInfo();
	std::string getAsString();
	void setFromString( std::string data );
	int getSeats();
	void setSeats( int newSeats );
};

