#include "PassengerCar.h"

PassengerCar::PassengerCar( const PassengerCar &carArg ) : CarBase( carArg ) {
	this->seats = carArg.seats;
}

virtual std::string PassengerCar::getInfo() {
	return this->brand + " " + this->model + ", rok produkcji: " + std::to_string( this->productionYear ) + ", " + std::to_string(this->seats) + " pasa¿erów, nr rejestracyjny: " + this->licenseNumber;
}

int PassengerCar::getSeats() {
	return this->seats;
}

void PassengerCar::setSeats( int newSeats ) {
	this->seats = seats;
}
