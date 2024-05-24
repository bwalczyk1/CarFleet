#include "PassengerCar.h"
#include<vector>
#include<stdexcept>

PassengerCar::PassengerCar( const PassengerCar &carArg ) : CarBase( carArg ) {
	this->seats = carArg.seats;
}

const std::string PassengerCar::TYPE = "PASSENGER";

std::string PassengerCar::getInfo() {
	return this->brand + " " + this->model + ", rok produkcji: " + std::to_string( this->productionYear ) + ", " + std::to_string(this->seats) + " pasa¿erów, nr rejestracyjny: " + this->licenseNumber;
}

std::string PassengerCar::getAsString() {
	return this->TYPE + ";" + this->brand + ";" + this->model + ";" + std::to_string( this->productionYear ) +
		";" + this->licenseNumber + ";" + std::to_string( this->mass ) + ";" + std::to_string( this->seats );
}

void PassengerCar::setFromString( std::string data ) {
	std::vector<std::string> args;
	// splits 'data' by 'del' character
	const std::string del = ";";
	int start, end = -1 * del.size();
	do {
		start = end + del.size();
		end = data.find( del, start );
		args.push_back( data.substr( start, end - start ) );
	} while ( end != -1 );
	if(args.size() < 6)
		throw std::invalid_argument("Not enough arguments in string");
	this->brand = args[0];
	this->model = args[1];
	this->productionYear = std::stoi( args[2] );
	this->licenseNumber = args[3];
	this->mass = std::stof( args[4] );
	this->seats = std::stoi( args[5] );
}

int PassengerCar::getSeats() {
	return this->seats;
}

void PassengerCar::setSeats( int newSeats ) {
	this->seats = seats;
}
