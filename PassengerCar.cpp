#include "PassengerCar.h"

PassengerCar::PassengerCar( const PassengerCar &carArg ) : CarBase( carArg ) {
	this->seats = carArg.seats;
}

int PassengerCar::getSeats() {
	return this->seats;
}

void PassengerCar::setSeats( int newSeats ) {
	this->seats = seats;
}