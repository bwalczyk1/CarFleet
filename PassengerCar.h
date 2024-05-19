#pragma once
#include "CarBase.h"
class PassengerCar : public CarBase {
private:
	int seats;
public:
	PassengerCar() : CarBase(), seats( 0 ) {};
	PassengerCar( std::string brandArg, std::string modelArg, int productionYearArg, std::string licenseNumberArg, float massArg, int seatsArg ) : CarBase( brandArg, modelArg, productionYearArg, licenseNumberArg, massArg ), seats( seatsArg ) {};
	PassengerCar( const PassengerCar &carArg );

	virtual std::string getInfo() {
		return this->brand + " " + this->model + ", rok produkcji: " + std::to_string( this->productionYear ) + ", " + std::to_string(this->seats) + " pasa¿erów, nr rejestracyjny: " + this->licenseNumber;
	}
	int getSeats();
	void setSeats( int newSeats );
};

