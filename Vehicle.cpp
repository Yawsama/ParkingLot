/*
 * Vehicle.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */
#include <iostream>
#include <string>
#include <sstream>
#include "Vehicle.h"
#include "Type.h"

using namespace std;

Vehicle::~Vehicle()
{
	//do nothing
}

Bus :: Bus(){}
Bus :: ~Bus(){};

/* returns the character 'B' to be used when signifying a filled Bus spot */
char Bus :: getchar(){
	return spotChar;
}

/* returns the name of the class. Used for testing purposes only */
string Bus :: getClass(){
	return "Bus";
}

Car :: Car(){}
Car :: ~Car(){};

/* returns the character 'C' to be used when signifying a filled Car spot */
char Car :: getchar(){
	return spotChar;
}

/* returns the name of the class. Used for testing purposes only */
string Car :: getClass(){
	return "Car";
}

Motorcycle :: Motorcycle(){}
Motorcycle :: ~Motorcycle(){}

/* returns the character 'M' to be used when signifying a filled Motorcycle spot */
char Motorcycle :: getchar(){
	return spotChar;
}

/* returns the name of the class. Used for testing purposes only */
string Motorcycle :: getClass(){
	return "Motorcycle";
}
