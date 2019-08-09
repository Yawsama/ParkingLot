/*
 * ParkingLot.h
 *
 *  Created on: Nov 28, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */

#ifndef PARKINGLOT_H_
#define PARKINGLOT_H_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Vehicle.h"
#include "Spot.h"
#include "Level.h"
#include "Type.h"

using namespace std;

/* The ParkingLot class uses the Level class to construct a full parking garage. It uses a vector of Levels, which
 * themselves are vectors of Spots, to create the garage.
 */
class ParkingLot {
	private:
		vector<Level> levels;
		const int NUM_OF_LEVELS = 5;
		int numLevels;
	public:
		ParkingLot();
		ParkingLot(int numLevels, int spotsLevel, int spotsRow);
		virtual ~ParkingLot();
		vector<Level> getLevels();
		string toString();
		int addCar(Car* usrVeh);
		int addMotor(Motorcycle* usrVeh);
		int addBus(Bus* usrVeh);
		int removeCar();
		int removeBus();
		int removeMotor();
};

#endif /* PARKINGLOT_H_ */
