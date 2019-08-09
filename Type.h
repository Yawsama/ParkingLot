	/*
 * Type.h
 *
 *  Created on: Nov 27, 2018
 *      Author: Advait Sankaramanchi
 *      CS 2336.001
 */

#ifndef TYPE_H_
#define TYPE_H_

/* this enum is used in the Spot class so that the system knows what kind of parking spot is at
 * a specific Spot, regardless of whether or not there is a vehicle currently on that Spot
 */
enum class Type{
	Motorcycle,
	Compact,
	Large
};


#endif /* TYPE_H_ */
