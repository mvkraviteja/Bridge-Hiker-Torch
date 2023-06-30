#include <iostream>
#include <vector>

using namespace std;
int default_hikers = 7;
int default_bridges = 3;
int counter;
int bridge_id;

class Bridge {

public:
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

	void setTimeToCrossBridge(float time) {
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
	char id;
	bool crossedBridge;
	

	Hiker() {
		// Set default values for the hiker : default speed and no torch
		// Have to be an incrementing number while object creation
	}

	// ID can be changed to a string too - have to check if this is required
	void setId(char id) {
		this->id = id;
	}

	char getId(void) {
		return id;
	}

	void acquireTorch() {
		// Get torch to this hiker
		this->torch = true;	
	}

	void releaseTorch() {
		// Relinquish torch
		this->torch = false;
	}

	void initTorch() {
		// Init torch
		this->torch = false;
	}

	void setSpeed(float speed) {
		speedInFeetPerMin = speed;
	}

	float getSpeed() {
		return speedInFeetPerMin;
	}

	void setCrossedBridge(bool set) {
		this->crossedBridge = set;
	}

	bool getCrossedBridge() {
		return crossedBridge;
	}
};

class setupEnvironment{
public :
	float totalTimeInMin;
	int noOfBridges, noOfHikers;

	vector<Bridge> bridges;
	vector<Hiker> hikers;

	setupEnvironment() {
		this->noOfBridges = default_bridges;
		this->noOfHikers = default_hikers;
		cout << " Default environment setup with " << this->noOfBridges << " bridges and " <<this->noOfHikers<< " hikers ...\n";
		// Have default number of bridges and hikers
		// Set the basic problem to run for completion
	}

	setupEnvironment(int bridgesCount, int hikersCount) {
		this->noOfBridges = bridgesCount;
		this->noOfHikers = hikersCount;
		cout << " Environment setup with " << this->noOfBridges << " bridges and " <<this->noOfHikers<< " hikers ...\n";
	}

	void addBridge(int length) {
		cout << "Adding bridge ... \n";
		Bridge b;
		b.setBridgeLength(length);
		b.setTimeToCrossBridge(0);
		bridges.push_back(b);
	}

	void updateBridgeCount() {
		this->noOfBridges++;
	}

	void addHiker(float speed) {
		cout << "Adding hiker ... \n";
		Hiker h;
		//h.setId(counter++);
		h.setId('A' + counter++);
		h.setSpeed(speed);
		h.initTorch();
		h.setCrossedBridge(false);
		hikers.push_back(h);
	}

	void updateHikerCount() {
		this->noOfHikers++;
	}

/*
	void populateHikerInfo() {
		for(int i = 1; i <= noOfHikers; i++) {
			Hiker h;
			h.setId(i);
			h.setSpeed
			hikers.push_back(h);
		}
	}
*/

	void initBridgeAndHikerInfo() {
		addBridge(100);
		addHiker(100);
		addHiker(50);
		addHiker(20);
		addHiker(10);
	}

/*
	float timeForCrossingBridge(vector<Hiker> start, vector<Hiker> end ) {
		if (start.empty()) {
			return;
		}
		
	}
*/

	void printStartAndEnd(vector<float> start, vector<float> end) {
		cout << "Start : ";
		for(auto iterator : start) {
			cout <<" " << iterator << ", ";
		}
		cout << endl;

		cout << "End : ";
		for(auto iterator : end) {
			cout <<" " << iterator << ", ";
		}
		cout << endl;



	}

	float calculateTimeToCrossBridge(int length) {
		// CORE LOGIC : for the problem	
		vector<float> start;
		vector<float> end;
		vector<float> timeForIteration;

		for(int i = 0; i < noOfHikers; i++) {
			float time = length/hikers[i].getSpeed();
			auto insertionIterator = upper_bound(start.cbegin(), start.cend(), time);
			start.insert(insertionIterator, time);
		}

		int startIndex = 0;
		int endIndex = 0;
		float totalTimeToCrossBridge = 0;
		while ( ! start.empty() ) {
			float time = 0;

			// Pick two from the start vector (remove from start vector)
			// Put it in end vector
			// Bring first one from the end vector and put it in start vector (push it to the end)
				// - remove two from beginning of start 
				// put it in end vector at the end
				// remove from begin of end vector and put it in start vector
			vector<float>::iterator startIterator;
			vector<float>::iterator endIterator;

			time += *start.begin();
			end.push_back(*start.begin());
			start.erase(start.begin());
			time = max(time, *start.begin());
			end.push_back(*start.begin());
			start.erase(start.begin());

			//printStartAndEnd(start, end);

			/* Check if start is empty again ? */
			if ( ! start.empty() ) {
				start.push_back(end[0]);
				time += *end.begin();
				end.erase(end.begin());
			}
			totalTimeToCrossBridge += time;
		}
		cout << endl;

		return totalTimeToCrossBridge;
	}

	void printEnvironmentInfo() {
		for (int i = 0; i < noOfHikers; i++) {
			cout << "Hiker " << i << " : id : " <<hikers[i].getId() << ", Speed : " << hikers[i].getSpeed() << endl;
		}
		float time;
		for(int i = 0; i < noOfBridges; i++) {
			time = bridges[i].getTimeToCrossBridge();
			if ( ! time ) {
				// Calculate the time to cross the bridge if that information is not already calculated
				time = calculateTimeToCrossBridge(bridges[i].getBridgeLength());
				cout <<" \t\t\t\t\t\t\tTotal time to cross the bridge was : " << time << " minutes" << endl;
				bridges[i].setTimeToCrossBridge(time);
				updateTotalTime(time);
			}
			cout << "Bridge - " << i << " , Length : " << bridges[i].getBridgeLength() << " and time to cross the bridge : " << time << endl;
		}
	}
		
	float getTotalTime(void) {
		//return totalTimeInMin;
		float totalTime = 0;
		for (int i = 0; i < noOfBridges; i++) {
			totalTime += bridges[i].getTimeToCrossBridge();
		}

		return totalTime;
	}

	void updateTotalTime(float time) {
		this->totalTimeInMin += time;
	}

};

// Method to read in information from the YAML / text file
void addBridgesAndHikers(int bridges, int hikers) {
	cout << "Adding " << bridges << " bridges and " << hikers << " hikers\n";
}


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
	*/

	int bridges, hikers;

	/* Read from YAML file - easy way to translate this as a test (testcases) */
	// TODO : Logic to translate the information from YAML to code 
	//addBridgesAndHikers(4, 3);

	// Read in information about the hikers from YAML
	// TODO : Couldnt get that working - reading in the yaml / yaml-cpp working 
	//environment.populateHikerInfo();


	// Read in information about the environment 
	//setupEnvironment environment;
	setupEnvironment environment(1,4);


	// Update environment with bridges and hiker information
	environment.initBridgeAndHikerInfo();
	// Stats of the environment
	environment.printEnvironmentInfo();
	//environment.calculateTimeToCrossBridge(bridge_id++);

	// Test Case : 2 
	environment.addBridge(250);
	environment.updateBridgeCount();
	environment.addHiker(2.5);
	environment.updateHikerCount();
	environment.printEnvironmentInfo();
	//environment.calculateTimeToCrossBridge(bridge_id++);

	// Test Case : 3 
	environment.addBridge(150);
	environment.updateBridgeCount();
	environment.addHiker(25);
	environment.updateHikerCount();
	environment.addHiker(15);
	environment.updateHikerCount();
	environment.printEnvironmentInfo();
	//environment.calculateTimeToCrossBridge(bridge_id++);

	cout << " \n\n\t\t\t\t\t\t\tTotal time taken to cross all bridges : " << environment.getTotalTime() << endl;
}


