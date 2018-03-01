//
// Created by jakub on 01-Mar-18.
//

#ifndef GOOGLEHASHCODE_LOGIC_H_H
#define GOOGLEHASHCODE_LOGIC_H_H
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>

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
    int endTimeTemp;
};

struct Car {;
    Position position;
    vector<int> takenRides;
    int currentRide;
    int status; // 0 - idle, 1 - rides to start, 2 - wait, 3 - rides to finish;
};

struct Info {
    int rows;
    int columns;
    int vehicles;
    int rides;
    int bonus;
    int steps;
};

vector<Ride> readRides(const string& fileName, Info &info);

int travellingTime(Position start, Position end);

bool areEqual(Position a, Position b);

Ride* getRideById(int id, const std::vector<Ride> & rides);

bool moveCar(Car &car, Position pos);

void processMove(Car * car, int currentTick, const std::vector<Ride> & rides);

void writeRides(const std::string& fileName, std::vector<Car> cars);

void logic();


#endif //GOOGLEHASHCODE_LOGIC_H_H
