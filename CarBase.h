#pragma once
#include<string>
#include "FileWriteable.h"

class CarBase : public FileWriteable {
protected:
    std::string brand;
    std::string model;
    int productionYear;
    std::string licenseNumber;
    float mass;
public:
    CarBase() : productionYear(0), mass(0) {};
    CarBase( std::string brandArg, std::string modelArg, int productionYearArg, std::string licenseNumberArg, float massArg ) :
        brand( brandArg ), model( modelArg ), productionYear( productionYearArg ), licenseNumber(licenseNumberArg), mass(massArg) {}
    CarBase( const CarBase &carArg );

    std::string getBrand();
    std::string getModel();
    int getProductionYear();
    std::string getLicenseNumber();
    float getMass();
    virtual std::string getAsString() = 0;
    virtual void setFromString( std::string data ) = 0;

    void setBrand( std::string newBrand );
    void setModel( std::string newModel );
    void setProductionYear( int newProductionYear );
    void setLicenseNumber( std::string newLicenseNumber );
    void setMass( float newMass );

    virtual std::string getInfo() = 0;
};

