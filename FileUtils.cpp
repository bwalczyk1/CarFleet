#include "FileUtils.h"
#include "PassengerCar.h"
#include "DeliveryCar.h"
#include <fstream>
#include <iostream>

void FileUtils::writeCarVector( std::string fileName, std::vector<CarBase*> &vect ) {
	std::ofstream file( fileName );
	if ( !file.is_open() )
		throw std::invalid_argument( "Could not open file '" + fileName + "'" );
	for ( CarBase *obj : vect ) {
		file << obj->getAsString() << std::endl;
	}
	file.close();
}

void FileUtils::readCarVector( std::string fileName, std::vector<CarBase*> &vect ) {
	std::ifstream file( fileName );
	if ( !file.is_open() )
		throw std::invalid_argument( "Could not open file '" + fileName + "'" );
	vect.clear();
	std::string line;
	for ( int i = 1; std::getline( file, line ); i++ ) {
		int first = line.find( ';' );
		std::string type = line.substr( 0, first );
		if ( type == PassengerCar::TYPE ) {
			PassengerCar *tmp = new PassengerCar();
			tmp->setFromString( line.substr( first + 1 ) );
			vect.emplace_back( tmp );
		}
		else if ( type == DeliveryCar::TYPE ) {
			DeliveryCar *tmp = new DeliveryCar();
			tmp->setFromString( line.substr( first + 1 ) );
			vect.emplace_back( tmp );
		}
		else
			std::cerr << "Unrecognized data at line " << i << " skipping" << std::endl;
	}
	vect.shrink_to_fit();
}