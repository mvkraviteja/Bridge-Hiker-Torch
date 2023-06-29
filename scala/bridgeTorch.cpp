#include <iostream>

class Bridge {

	int lengthInFeet;
	float timeToCrossBridgeInMin;
	int id;

	Bridge() {
		// Has to be an incrementing number while object creation
		// Set default bridge length
		// Set default time to cross the bridge
	}

	void setBridgeLength(int length) {
		lengthInFeet = length;
	}

	int getBridgeLength() {
		return lengthInFeet;
	}

	void setTimeToCrossBridge(int time) {
		timeToCrossBridgeInMin = time;
	}

	float getTimeToCrossBridge() {
		return timeToCrossBridgeInMin;
	}
};

class Hiker {

public:

	float speedInFeetPerMin;
	bool torch;
	int id;

	Hiker() {
		// Set default values for the hiker : default speed and no torch
		// Have to be an incrementing number while object creation
	}

	void getTorch() {
		// Get torch to this hiker
	}

	void releaseTorch() {
		// Relinquish torch
	}

	void setSpeed(float speed) {
		speedInFeetPerMin = speed;
	}

	float getSpeed() {
		return speedInFeetPerMin;
	}

};

/*
class setupEnvironment{
	float totalTimeInMin;

	setupEnvironment() {
		// Have default number of bridges and hikers
		// Set the basic problem to run for completion
	}

	float getTotalTime(void) {
		return totalTimeInMin;
	}
}
*/


int main() {
	// Either use an object to setup environment or use test-helper functions or objects to simulate different scenarios
	/* Things to consider while building the application
		- Easy to scale ? 
		- Easy to test ?
			- Easy to add new test-cases / variants of tests ?
	*/

	/* Solution :
		- Start of the bridge
		- End of the bridge
			(we need to know what set of hikers are on what side of the bridge)
				- Start, end variables?
}

