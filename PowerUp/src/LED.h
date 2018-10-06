/*
 * LED.h
 *
 *  Created on: Sep 17, 2018
 *      Author: romellmertis
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_

#include <mindsensors.h>

using mindsensors::CANLight;

class LED {
public:
	LED();
	void green();
	void stop();

private:

	CANLight *led;

};

#endif /* SRC_LED_H_ */
