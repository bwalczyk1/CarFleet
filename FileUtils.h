#pragma once
#include<vector>
#include "CarBase.h"

namespace FileUtils {
	void writeCarVector( std::string fileName, std::vector<CarBase*> &vect );
	void readCarVector( std::string fileName, std::vector<CarBase*> &vect );
};

