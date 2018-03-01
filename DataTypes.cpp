#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Position {
    int x;
    int y;
};

struct Ride {
    int id;
    Position goFrom;
    Position goTo;
    int timeStart;
    int timeFinish;
    bool available;
};

struct Car {
    Position position;
    vector<Ride> takenRides;
    bool busy;
};


vector<Ride> readVector(const string& fileName) {
    ifstream input;
    vector<Ride> vec;
    input.open(fileName);
    if (input) {
        int first = 0;
        int val;
        int index = 0;
        while (input >> val) {

            Ride newRide;
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