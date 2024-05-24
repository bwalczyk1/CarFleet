#pragma once
#include<string>

class FileWriteable {
public:
	virtual std::string getAsString() = 0;
	virtual void setFromString( std::string data ) = 0;
};