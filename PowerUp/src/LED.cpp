/*
 * LED.cpp
 *
 *  Created on: Sep 17, 2018
 *      Author: romellmertis
 */

#include <LED.h>

LED::LED() {
	led = new CANLight(0);

}
void LED::green() {
	led->ShowRGB(0, 255, 0);

}
void LED::stop() {
	led->ShowRGB(0, 0, 0);

}
