/*
 * Level.cpp
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

using namespace std;

/* This default constructor creates a level based off the default values. It organizes the Spots based
 * on the default proportions. The constructor does not handle the spaces between rows, as that is addressed in the
 * toString() method.
 */
Level::Level() {
	spotsLevel = SPOTS_PER_LEVEL;
	spotsRow = SPOTS_PER_ROW;
	numLargeSpots = spotsLevel / 5;
	numMotorSpots = spotsLevel / 5;
	Vehicle* veh = NULL;
	for(int k = 0; k < SPOTS_PER_LEVEL; k++){
		if(k < numLargeSpots)
		{
			Spot mySpot(Type::Large, veh);
			spots.push_back(mySpot);
		}
		if(k >= numLargeSpots && k < spotsRow)
		{
			Spot mySpot(Type::Compact, veh);
			spots.push_back(mySpot);
		}
		if(k >= spotsRow && k < spotsRow * 2)
		{
			Spot mySpot(Type::Compact, veh);
			spots.push_back(mySpot);
		}
		if(k >= spotsRow * 2 && k < spotsLevel - numMotorSpots)
		{
			Spot mySpot(Type::Compact, veh);
			spots.push_back(mySpot);
		}
		if(k >= spotsLevel - numMotorSpots)
		{
			Spot mySpot(Type::Motorcycle, veh);
			spots.push_back(mySpot);
		}
	}
}

/* This overloaded constructor creates a level based off of user inputed values. It then organizes the Spots
 * based on the default proportions. The constructor does not handle the spaces between rows, as that is addressed in the
 * toString() method.
 */
Level :: Level(int spotsLevel, int spotsRow){
	this->spotsLevel = spotsLevel;
	this->spotsRow = spotsRow;
	numLargeSpots = spotsLevel / 5;
	numMotorSpots = spotsLevel / 5;
	Vehicle* veh = NULL;
	for(int k = 0; k < SPOTS_PER_LEVEL; k++){
		if(k < numLargeSpots)
		{
			Spot mySpot(Type::Large, veh);
			spots.push_back(mySpot);
		}
		if(k >= numLargeSpots && k < spotsRow)
		{
			Spot mySpot(Type::Compact, veh);
			spots.push_back(mySpot);
		}
		if(k >= spotsRow && k < spotsRow * 2)
		{
			Spot mySpot(Type::Compact, veh);
			spots.push_back(mySpot);
		}
		if(k >= spotsRow * 2 && k < spotsLevel - numMotorSpots)
		{
			Spot mySpot(Type::Compact, veh);
			spots.push_back(mySpot);
		}
		if(k >= spotsLevel - numMotorSpots)
		{
			Spot mySpot(Type::Motorcycle, veh);
			spots.push_back(mySpot);
		}
	}
}

Level::~Level() {}

/* returns the vector of Spots */
vector<Spot> Level :: getSpots(){
	return spots;
}

/* sets the vector of Spots to the spots vector in the formal parameter */
void Level :: setSpots(vector<Spot> spots){
	this->spots = spots;
}

/* Forms the Level into how it will be presented to the user. It returns the
 * vector of Spots for the Level with the spaces added between rows.
 * This ParkingLot toString() uses this method when updating the output after vehicles are
 * added or removed.
 */
string Level :: toString(){
	string ret = "";
	for(int k = 0; k < spotsLevel; k++)
	{
		Vehicle* machine = spots[k].getVehicle();
		string charAtSpot;
		if(machine == 0) //if the Spot has no vehicle, it gets the type of Spot and adds it to the return string
		{
			Type theSpotType = spots[k].getType();
			switch(theSpotType){
				case Type::Motorcycle :
					charAtSpot = 'm';
					break;
				case Type::Compact:
					charAtSpot = 'c';
					break;
				case Type::Large :
					charAtSpot = 'l';
					break;
			}
		}
		else
		{
			charAtSpot = machine->getchar();
		}
		ret += charAtSpot;
		if((k+1) % spotsRow == 0) //adds in the spaces at the end of each row
		{
			ret += " ";
		}
	}
	return ret;
}










