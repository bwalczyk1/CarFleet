#pragma once
#include "CarBase.h"
class DeliveryCar : public CarBase {
private:
	float maxAuthorisedMass;
public:
	DeliveryCar() : CarBase(), maxAuthorisedMass( 0 ) {};
	DeliveryCar( std::string brandArg, std::string modelArg, int productionYearArg, std::string licenseNumberArg, float massArg, float maxAuthorisedMassArg ) : CarBase( brandArg, modelArg, productionYearArg, licenseNumberArg, massArg ), maxAuthorisedMass( maxAuthorisedMassArg ) {};
	DeliveryCar( const DeliveryCar &carArg );

	std::string getInfo();
	float getMaxAuthorisedMass();
	void setMaxAuthorisedMass( float newMaxAuthorisedMass );
	float getMaxLoad();
};

