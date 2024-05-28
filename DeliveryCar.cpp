#include "DeliveryCar.h"
#include<vector>
#include<stdexcept>

DeliveryCar::DeliveryCar( const DeliveryCar &carArg ) : CarBase( carArg ) {
	this->maxAuthorisedMass = carArg.maxAuthorisedMass;
}

const std::string DeliveryCar::TYPE = "DELIVERY";

std::string DeliveryCar::getInfo() {
	return this->brand + " " + this->model + ", rok produkcji: " + std::to_string(this->productionYear) + ", maks. ładunek: " + std::to_string(this->getMaxLoad()) + " kg, nr rejestracyjny: " + this->licenseNumber;
}

std::string DeliveryCar::getAsString() {
	return this->TYPE + ";" + this->brand + ";" + this->model + ";" + std::to_string( this->productionYear ) +
		";" + this->licenseNumber + ";" + std::to_string( this->mass ) + ";" + std::to_string( this->maxAuthorisedMass );
}

void DeliveryCar::setFromString( std::string data ) {
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
	this->maxAuthorisedMass = std::stof( args[5] );
}

float DeliveryCar::getMaxAuthorisedMass() {
	return this->maxAuthorisedMass;
}

void DeliveryCar::setMaxAuthorisedMass( float newMaxAuthorisedMass ) {
	this->maxAuthorisedMass = newMaxAuthorisedMass;
}

float DeliveryCar::getMaxLoad() {
	return this->maxAuthorisedMass - this->mass;
}
