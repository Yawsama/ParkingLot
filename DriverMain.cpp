/*
 * DriverMain.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */
#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <vector>
#include "Vehicle.h"
#include "Spot.h"
#include "Level.h"
#include "Type.h"
#include "ParkingLot.h"

using namespace std;

/* Creates the lot based on whether the user wants to use the default lot or a custom lot.
 * This decision is passed into the method through the char c parameter.
 * Return either the default lot or a custom lot.
 */
ParkingLot initializeLot(char c){
	if(c == 'd')
	{
		ParkingLot myLot;
		return myLot;
	}
	else
	{
		cout << "How many levels would you like in the garage?" << endl;
		int numLevels;
		cin >> numLevels;
		cout << endl;

		cout << "How many parking spots would you like per level? (value needs to be divisible by 5)" << endl;
		int numSpots;
		while(true)
		{
			cin >> numSpots;
			cout << endl;
			if(numSpots % 5 != 0)
			{
				cout << "Invalid input. Enter a value that is divisible by 5" << endl;
			}
			else
			{
				break;
			}

		}

		cout << "How many spots would you like per row?" << endl;
		int spotsRow;
		cin >> spotsRow;
		cout << endl;
		ParkingLot myLot(numLevels, numSpots, spotsRow);
		return myLot;
	}
}

int main(){

	cout << "Would you like to use the default values (enter d if so) or would you like to enter your own values (enter e if so)?" << endl;
	char defaultAnswer;
	cin >> defaultAnswer;
	cout << endl;
	ParkingLot myLot = initializeLot(defaultAnswer);
	cout << "The Parking Garage" << endl;
	cout<< myLot.toString() << endl;

	while(true)
	{
		cout << "Would you like to park or remove from the garage? (enter p for park or r for remove)" << endl;
		char parkOrRemove;
		cin >> parkOrRemove;
		cout << endl;
		if(parkOrRemove == 'p')
		{
			cout << "Would you like to park a car, bus, or motorcycle? (enter c for car, b for bus, or m for motorcycle)" << endl;
			char whichVehicle;
			cin >> whichVehicle;
			cout << endl;
			int canAdd = -1;
			if(whichVehicle == 'c')
			{
				Car* usrVeh = new Car();
				canAdd = myLot.addCar(usrVeh);
				if(canAdd == 0)
				{
					cout << "Parking a car" << endl;
					cout << myLot.toString();
					cout << endl;
				}
				else
				{
					cout << "Sorry, there is no space for a car" << endl;
					cout << endl;
				}
			}
			else if(whichVehicle == 'b')
			{
				Bus* usrVeh = new Bus();
				canAdd = myLot.addBus(usrVeh);
				if(canAdd == 0)
				{
					cout << "Parking a bus" << endl;
					cout << myLot.toString();
					cout << endl;
				}
				else
				{
					cout << "Sorry, there is no more space for a bus" << endl;
					cout << endl;
				}
			}
			else if(whichVehicle == 'm')
			{
				Motorcycle* usrVeh = new Motorcycle();
				canAdd = myLot.addMotor(usrVeh);
				if(canAdd == 0)
				{
					cout << "Parking a motorcycle" << endl;
					cout << myLot.toString();
					cout << endl;
				}
				else
				{
					cout << "Sorry, there is no more space for a motorcycle" << endl;
					cout << endl;
				}
			}
		}
		else if(parkOrRemove == 'r')
		{
			cout << "Would you like to remove a car, bus, or motorcycle? (enter c for car, b for bus, or m for motorcycle)" << endl;
			char whichVehicle;
			cin >> whichVehicle;
			cout << endl;
			int canRemove = -1;
			if(whichVehicle == 'c')
			{
				canRemove = myLot.removeCar();
				if(canRemove == 0)
				{
					cout << "Removing a car" << endl;
					cout << myLot.toString();
					cout << endl;
				}
				else
				{
					cout << "Sorry, there are no cars to remove" << endl;
					cout << endl;
				}
			}
			else if(whichVehicle == 'b')
			{
				canRemove = myLot.removeBus();
				if(canRemove == 0)
				{
					cout << "Removing a bus" << endl;
					cout << myLot.toString();
					cout << endl;
				}
				else
				{
					cout << "Sorry, there are no busses to remove" << endl;
					cout << endl;
				}
			}
			else if(whichVehicle == 'm')
			{
				canRemove = myLot.removeMotor();
				if(canRemove == 0)
				{
					cout << "Removing a motorcycle" << endl;
					cout << myLot.toString();
					cout << endl;
				}
				else
				{
					cout << "Sorry, there are no motorcycles to remove" << endl;
					cout << endl;
				}
			}
		}

		cout << "Would you like to continue? [y/n]" << endl;
		char cont;
		cin >> cont;
		cout << endl;
		if(cont == 'n')
		{
			cout << "Have a good day!" << endl;
			break;
		}
	}
	return 0;
}



