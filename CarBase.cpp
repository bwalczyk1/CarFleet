#include "CarBase.h"

CarBase::CarBase( const CarBase &carArg ) {
    this->brand = carArg.brand;
    this->model = carArg.model;
    this->productionYear = carArg.productionYear;
    this->licenseNumber = carArg.licenseNumber;
    // this->vehicleType = carArg.vehicleType;
    this->mass = carArg.mass;
}

std::string CarBase::getBrand() {
    return this->brand;
}

std::string CarBase::getModel() {
    return this->model;
}

int CarBase::getProductionYear() {
    return this->productionYear;
}

std::string CarBase::getLicenseNumber() {
    return this->licenseNumber;
}

//VehicleType CarBase::getVehicleType() {
//    return this->vehicleType;
//}

float CarBase::getMass() {
    return this->mass;
}

void CarBase::setBrand( std::string newBrand ) {
    this->brand = newBrand;
}

void CarBase::setModel( std::string newModel ) {
    this->model = newModel;
}

void CarBase::setProductionYear( int newProductionYear ) {
    this->productionYear = newProductionYear;
}

void CarBase::setLicenseNumber( std::string newLicenseNumber ) {
    this->licenseNumber = newLicenseNumber;
}

//void CarBase::setVehicleType( VehicleType newVehicleType ) {
//    this->vehicleType = newVehicleType;
//}

void CarBase::setMass( float newMass ) {
    this->mass = newMass;
}
