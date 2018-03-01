#include <iostream>
#include <vector>
#include <fstream>

#include "Logic.h"

using namespace std;

void printRide(Ride ride){
    cout << "Ride #" << ride.id << " ";
	cout << ride.goFrom.x << " ";
	cout << ride.goFrom.y << " ";
	cout << ride.goTo.x << " ";
	cout << ride.goTo.y << " ";
	cout << ride.timeStart << " ";
	cout << ride.timeFinish << " ";
	cout << endl;
}

int main() {
	vector<Ride> rides;

    logic();

	return 0;
}
