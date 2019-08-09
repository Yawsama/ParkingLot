/*
 * Spot.h
 *
 *  Created on: Nov 27, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */

#ifndef SPOT_H_
#define SPOT_H_
#include "Type.h"
#include "Vehicle.h"

/* The Spot class creates a Parking Spot. It has a spotType (large, compact, motorcycle) and a vehicleType(Car, Bus, Motorcycle) */
class Spot {
	private:
		Type spotType;
		Vehicle* vehicleType;
	public:
		Spot();
		Spot(Type spotType, Vehicle* vehicleType);
		virtual ~Spot();
		Type getType();
		Vehicle* getVehicle();
		void setVehicle(Vehicle* machine);
};

#endif /* SPOT_H_ */
