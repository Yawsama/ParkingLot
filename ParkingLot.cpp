/*
 * ParkingLot.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Vehicle.h"
#include "Spot.h"
#include "Level.h"
#include "Type.h"
#include "ParkingLot.h"

using namespace std;

/* The default constructor creates the vector of Levels based on the default number of levels provided */
ParkingLot::ParkingLot() {
	numLevels = NUM_OF_LEVELS;
	for(int k = 0; k < numLevels; k++)
	{
		Level myLevel = Level();
		levels.push_back(myLevel);
	}
}

/* The overloaded constructor takes the user input and creates the vector of Levels. The user input for
 * this constructor defines the number of levels, the amount of spots per level, and the amount of
 * spots per row.
 */
ParkingLot :: ParkingLot(int numLevels, int spotsLevel, int spotsRow){
	this->numLevels = numLevels;
	for(int k = 0; k < numLevels; k++)
	{
		Level myLevel = Level(spotsLevel, spotsRow);
		levels.push_back(myLevel);
	}
}

ParkingLot::~ParkingLot() {}

/* returns the vector of levels */
vector<Level> ParkingLot :: getLevels(){
	return levels;
}

/* Uses the Level toString() method to display each vector of Spots one level at a time */
string ParkingLot :: toString(){
	string ret = "";
	for(int k = 0; k < numLevels; k++)
	{
		ret += "Level" + to_string(k) + ": ";
		ret += levels[k].toString() + "\n";
	}
	return ret;
}

/* Adds a Car into the ParkingLot. Returns 0 if it is added and -1 if it is not, */
int ParkingLot :: addCar(Car* usrVeh){
	int addedOrNot = -1;
	for(int k = 0; k < levels.size(); k++)
	{
		vector<Spot> spots = levels[k].getSpots(); //accesses the vector of Spots at the "k" index of the Levels vector
		for(int i= 0; i < spots.size(); i++)
		{
			Vehicle* myVeh = spots[i].getVehicle();
			if(myVeh == 0) //true if there is no vehicle at the spot, since no vehicle means NULL
			{
				if(spots[i].getType() == Type::Large || spots[i].getType() == Type::Compact)
				{
					spots[i].setVehicle(usrVeh);
					levels[k].setSpots(spots);//Sets the vehicle at the Spot to the Car provided in the formal parameter
					addedOrNot = 0;
					return addedOrNot;
				}
			}
		}
	}
	return addedOrNot;
}

/* Removes a Car from the ParkingLot. Returns 0 if it is removed and -1 if it is not, */
int ParkingLot :: removeCar(){
	int removedOrNot = -1;
	for(int k = 0; k < levels.size(); k++)
	{
		vector<Spot> spots = levels[k].getSpots(); //accesses the vector of Spots at the "k" index of the Levels vector
		for(int i= 0; i < spots.size(); i++)
		{
			Vehicle* myVeh = spots[i].getVehicle();
			if(myVeh != 0) //true if there is a vehicle at the spot
			{
				if(myVeh->getchar() == 'C')
				{
					spots[i].setVehicle(NULL); //removes the vehicle from that spot and sets it to NULL
					levels[k].setSpots(spots);
					removedOrNot = 0;
					return removedOrNot;
				}
			}
		}
	}
	return removedOrNot;
}

/* Adds a Motorcycle into the ParkingLot. Returns 0 if it is added and -1 if it is not, */
int ParkingLot :: addMotor(Motorcycle* usrVeh){
	int addedOrNot = -1;
	for(int k = 0; k < levels.size(); k++)
	{
		vector<Spot> spots = levels[k].getSpots(); //accesses the vector of Spots at the "k" index of the Levels vector
		for(int i= 0; i < spots.size(); i++)
		{
			Vehicle* myVeh = spots[i].getVehicle();
			if(myVeh == 0) //true if there is no vehicle at the spot, since no vehicle means NULL
			{
				spots[i].setVehicle(usrVeh);
				levels[k].setSpots(spots);//Sets the vehicle at the Spot to the Motorcycle provided in the formal parameter
				addedOrNot = 0;
				return addedOrNot;
			}
		}
	}
	return addedOrNot;
}

/* Removes a Motorcycle from the ParkingLot. Returns 0 if it is added and -1 if it is not, */
int ParkingLot :: removeMotor(){
	int removedOrNot = -1;
	for(int k = 0; k < levels.size(); k++)
	{
		vector<Spot> spots = levels[k].getSpots(); //accesses the vector of Spots at the "k" index of the Levels vector
		for(int i= 0; i < spots.size(); i++)
		{
			Vehicle* myVeh = spots[i].getVehicle();
			if(myVeh != 0) //true if there is a vehicle at the spot
			{
				if(myVeh->getchar() == 'M')
				{
					spots[i].setVehicle(NULL); //removes tthe vehicle from the spot and sets it to NULL
					levels[k].setSpots(spots);
					removedOrNot = 0;
					return removedOrNot;
				}
			}
		}
	}
	return removedOrNot;
}

/* Adds a Bus into the ParkingLot. Returns 0 if it is added and -1 if it is not, */
int ParkingLot :: addBus(Bus* usrVeh){
	int addedOrNot = -1;
	for(int k = 0; k < levels.size(); k++)
	{
		vector<Spot> spots = levels[k].getSpots();
		for(int i= 0; i < spots.size(); i++)
		{
			Vehicle* myVeh = spots[i].getVehicle(); //accesses the vector of Spots at the "k" index of the Levels vector
			int count  = 0;
			bool enoughSpots = false;
			for(int j = i; (j < i + 5) && (j < spots.size()); j++) //loop used to check the next five spots
			{
				if((spots[j].getVehicle() != 0) || (spots[j].getType() != Type::Large))
				{
					enoughSpots = false;
					break;
				}
				else //only count Spots that have a Large Type and a null value for vehicles
				{
					enoughSpots = true;
					count = count + 1;
				}
			}
			if(enoughSpots && count == 5)
			{
				addedOrNot = 0;
				for(int x = i; x < i + 5; x++)
				{
					spots[x].setVehicle(usrVeh); //Sets the vehicle at the Spot to the Bus provided in the formal parameter;
				}
				levels[k].setSpots(spots);
				return addedOrNot;
			}
		}
	}
	return addedOrNot;
}

/* Removes a Car from the ParkingLot. Returns 0 if it is removed and -1 if it is not, */
int ParkingLot :: removeBus(){
	int removedOrNot = -1;
	for(int k = 0; k < levels.size(); k++)
	{
		vector<Spot> spots = levels[k].getSpots();
		for(int i= 0; i < spots.size(); i++)
		{
			Vehicle* myVeh = spots[i].getVehicle(); //accesses the vector of Spots at the "k" index of the Levels vector
			int count  = 0;
			bool filledSpots = false;
			for(int j = i; (j < i + 5) && (j < spots.size()); j++) //loop used to check the next five spots
			{
				if((myVeh == 0))
				{
					filledSpots = false;
					i = i + 1;
					break;
				}
				if((myVeh != 0) && (myVeh->getchar() == 'B'))//only count Spots that have a Large Type and a null value for vehicles
				{
					filledSpots = true;
					count = count + 1;
				}
			}
			if(filledSpots && count == 5)
			{
				removedOrNot = 0;
				for(int x = i; x < i + 5; x++)
				{
					spots[x].setVehicle(NULL); //Sets the vehicle at the Spot to the Bus provided in the formal parameter;
				}
				levels[k].setSpots(spots);
				return removedOrNot;
			}
		}
	}
	return removedOrNot;
}






