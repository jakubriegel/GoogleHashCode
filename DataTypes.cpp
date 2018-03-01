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

struct Car {;
    Position position;
    vector<Ride> takenRides;
    bool busy;
};

struct Info {
    int rows;
    int columns;
    int vehicles;
    int rides;
    int bonus;
    int steps;
};

vector<Ride> readRides(const string& fileName, Info &info) {
    ifstream input;
    vector<Ride> vec;
    input.open(fileName);
    if (input) {
        int first = 0;
        int val;
        int index = 0;
        int vecIndex = 0;
        int a, b, c, d, e, f;
        while (input >> val) {
            if (first < 6) {
                switch(first){
                    case 0:
                        info.rows = val;
                        break;
                    case 1:
                        info.columns = val;
                        break;
                    case 2:
                        info.vehicles = val;
                        break;
                    case 3:
                        info.rides = val;
                        break;
                    case 4:
                        info.bonus = val;
                        break;
                    case 5:
                        info.steps = val;
                        index = 0;
                        break;
                    default:
                        break;
                }
                first++;
                continue;

            }
            switch (index) {
                case 0:
                    a = val;
                    break;
                case 1:
                    b = val;
                    break;
                case 2:
                    c = val;
                    break;
                case 3:
                    d = val;
                    break;
                case 4:
                    e = val;
                    break;
                case 5:
                    f = val;
                    Ride newRide;
                    newRide.id = vec.size();
                    newRide.goFrom.x = a;
                    newRide.goFrom.y = b;
                    newRide.goTo.x = c;
                    newRide.goTo.y = d;
                    newRide.timeStart = e;
                    newRide.timeFinish = f;
                    newRide.available = true;
                    vec.push_back(newRide);
                    index = -1;
                    break;
                default:
                    break;
            }
            index++;




        }
    }
    input.close();

    return vec;
}