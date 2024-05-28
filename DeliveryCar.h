#pragma once
#include "CarBase.h"
class DeliveryCar : public CarBase {
private:
	float maxAuthorisedMass;
public:
	static const std::string TYPE;

	DeliveryCar() : CarBase(), maxAuthorisedMass( 0 ) {};
	DeliveryCar( std::string brandArg, std::string modelArg, int productionYearArg, std::string licenseNumberArg, float massArg, float maxAuthorisedMassArg ) : CarBase( brandArg, modelArg, productionYearArg, licenseNumberArg, massArg ), maxAuthorisedMass( maxAuthorisedMassArg ) {};
	DeliveryCar( const DeliveryCar &carArg );

	std::string getInfo();
	std::string getAsString();
	void setFromString( std::string data );
	float getMaxAuthorisedMass();
	void setMaxAuthorisedMass( float newMaxAuthorisedMass );
	float getMaxLoad();
};

