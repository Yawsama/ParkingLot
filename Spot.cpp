/*
 * Spot.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */

#include <iostream>
#include <string>
#include <sstream>
#include "Spot.h"
#include "Type.h"
#include "Vehicle.h"

using namespace std;

Spot::Spot() {
	spotType = Type::Large;
	vehicleType = NULL;
}

Spot::Spot(Type spotType, Vehicle* vehicleType){
	this->spotType = spotType;
	this->vehicleType = vehicleType;
}

Spot::~Spot() {}

/* returns the type of parking spot for a specific Spot object */
Type Spot :: getType(){
	return spotType;
}

/* returns the vehicle that is on a specific Spot object. If there is no vehicle, this value is NULL */
Vehicle* Spot :: getVehicle(){
	return vehicleType;
}

/* used in the add and remove methods. It resets the Vehicle on the spot depending on which function the user is calling */
void Spot :: setVehicle(Vehicle* machine){
	vehicleType = machine;
}

