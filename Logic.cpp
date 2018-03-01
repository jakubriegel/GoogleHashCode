#include <iostream>
#include <cmath>
#include "DataTypes.cpp"

int travellingTime(Position start, Position end){
    return abs(start.x-end.x) + abs(start.y-end.y);
}

void logic(){

    std::vector<Ride> rides;
    std::vector<Car> cars;
    Info info;
    rides = readRides("a_example.in", info);
    int ticks = info.rides;//;1; // will read from data

    for(int currentTick = 0; currentTick < ticks; currentTick++){
        for(Ride & r : rides) if(r.available) if(r.timeFinish <= currentTick) r.available = false;
        for(Car & c : cars){
            if(!c.busy){
                std::vector<Ride*> possibleRides{};
                for(Ride & r : rides) if(r.available){
                        int totalTime = 0;
                        totalTime += travellingTime(c.position, r.goFrom);
                        if(totalTime + currentTick < r.timeStart) totalTime += (totalTime + currentTick);
                        totalTime += travellingTime(r.goFrom, r.goTo);
                        if(currentTick + totalTime < r.timeFinish){
                            possibleRides.push_back(&r);
                        }
                    }
            }
            else{
                // move
            }
        }


    }


}

