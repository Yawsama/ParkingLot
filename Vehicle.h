/*
 * Vehicle.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */

#ifndef _Vehicle_h_
#define _Vehicle_h_

#include <iostream>
#include <string>
#include <sstream>
#include "Type.h"

using namespace std;

/* Vehicle is a virtual class that is used to create the three different types of vehicles */
class Vehicle{
	public:
		virtual ~Vehicle();
		virtual char getchar() = 0;
		virtual string getClass() = 0;
};

/* Bus extends vehicle and is used to create the Bus object and allows the Level class to use the 'B' character */
class Bus: public Vehicle{
	private:
		const char spotChar = 'B';
	public:
		Bus();
		virtual ~Bus();
		char getchar();
		string getClass();
};

/* Car extends vehicle and is used to create the Car object and allows the Level class to use the 'C' character */
class Car: public Vehicle{
	private:
		const char spotChar = 'C';
	public:
		Car();
		virtual ~Car();
		char getchar();
		string getClass();
};

/* Motorcycle extends vehicle and is used to create the Motorcycle object and allows the Level class to use the 'M' character */
class Motorcycle: public Vehicle{
	private:
		const char spotChar = 'M';
	public:
		Motorcycle();
		virtual ~Motorcycle();
		char getchar();
		string getClass();
};

#endif

