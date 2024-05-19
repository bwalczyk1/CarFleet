#include "DeliveryCar.h"

DeliveryCar::DeliveryCar( const DeliveryCar &carArg ) : CarBase( carArg ) {
	this->maxAuthorisedMass = carArg.maxAuthorisedMass;
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