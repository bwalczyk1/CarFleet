#include "DeliveryCar.h"

DeliveryCar::DeliveryCar( const DeliveryCar &carArg ) : CarBase( carArg ) {
	this->maxAuthorisedMass = carArg.maxAuthorisedMass;
}

virtual std::string DeliveryCar::getInfo() {
	return this->brand + " " + this->model + ", rok produkcji: " + std::to_string( this->productionYear ) + ", maks. ³adunek: " + std::to_string(this->getMaxLoad()) + "kg, nr rejestracyjny: " + this->licenseNumber;
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
