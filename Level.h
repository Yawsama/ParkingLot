/*
 * Level.h
 *
 *  Created on: Nov 28, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Vehicle.h"
#include "Spot.h"

using namespace std;

/* The Level class uses a vector of Spots to create each individual level of the parking garage.
 * Ultimately, the Parking garage will be a vector of levels and each level will be a vector of spots.
 */
class Level {
	private:
		vector<Spot> spots;
		const int SPOTS_PER_LEVEL = 30;
		int spotsLevel;
		int numLargeSpots;
		int numMotorSpots;
		const int SPOTS_PER_ROW = 10;
		int spotsRow;
	public:
		Level();
		Level(int spotsLevel, int spotsrow);
		virtual ~Level();
		vector<Spot> getSpots();
		string toString();
		void setSpots(vector<Spot> spots);
};

#endif /* LEVEL_H_ */
