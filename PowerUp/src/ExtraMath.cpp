/*
 * ExtraMath.cpp
 *
 *  Created on: Sep 23, 2018
 *      Author: romellmertis
 */

#include <ExtraMath.h>
#include <iostream>
#include <string>

ExtraMath::ExtraMath() {

}
double ExtraMath::clamp(double val, double min, double max) {
	if (val <= min)
		val = min;
	else if (val >= max)
		val = max;

	return val;
}
