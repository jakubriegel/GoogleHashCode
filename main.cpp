#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct position {
	int x;
	int y;
};

struct ride {
	position goFrom;
	position goTo;
	int timeStart;
	int timeFinish;
};

struct car {
	position position;
	vector<ride> takenRides;
	bool busy;
};


vector<ride> readVector(const string& fileName) {
	ifstream input;
	vector<ride> vec;
	input.open(fileName);
	if (input) {
		int first = 0;
		int val;
		int index = 0;
		while (input >> val) {

			ride newRide;
			if (first <= 6) {
				
			}
			switch (index) {
			case 1:
				newRide.goFrom.x = val;
				break;
			case 2:
				newRide.goFrom.y = val;
				break;
			case 3:
				newRide.goTo.x = val;
				index = 0;
				break;
			default:
				break;
			}
				
			vec.push_back(newRide);
			
		}
	}
	input.close();

	return vec;
}



int main() {
	
	return 0;
}
