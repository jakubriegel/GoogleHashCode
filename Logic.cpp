#include "Logic.h"

Car::Car() {
    status = 0;
}

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

int travellingTime(Position start, Position end){
    return abs(start.x-end.x) + abs(start.y-end.y);
}

bool areEqual(Position a, Position b){
    return a.x == b.x && a.y == b.y;
}

Ride* getRideById(int id, const std::vector<Ride> & rides){
    for(const Ride & r : rides) if(r.id == id) return const_cast<Ride *>(&r);
}

bool moveCar(Car &car, Position pos) {
    if (car.position.x < pos.x) { car.position.x++; }
    else if (car.position.x > pos.x) { car.position.x--; }
    else if (car.position.y < pos.y) { car.position.y++; }
    else if (car.position.y > pos.y) { car.position.y--; }
    return (car.position.x == pos.x && car.position.y == pos.y);
}

void processMove(Car * car, int currentTick, const std::vector<Ride> & rides){
    auto* ride = getRideById(car->currentRide, rides);
    switch(car->status){
        case 1:
            if (areEqual(car->position, ride->goFrom)) {
                car->status = 2;
                if (currentTick >= ride->timeStart) {
                    car->status = 3;
                    moveCar(*car, ride->goTo);
                }
            }
            else moveCar(*car, ride->goFrom);
            break;
        case 2:
            if (currentTick >= ride->timeStart) {
                car->status = 3;
                moveCar(*car, ride->goTo);
            }
            break;
        case 3:
            if (areEqual(car->position, ride->goTo)) car->status = 0;
            else moveCar(*car, ride->goTo);
            break;
        default: break;
    }
}

void writeRides(const std::string& fileName, std::vector<Car*> cars) {
    std::ofstream output;
    output.open(fileName);
    if (output) {
        for (auto curCar : cars) {
            output << curCar->takenRides.size() << " ";
            for (auto e : curCar->takenRides) {
                output << e << " ";
            }
            output << endl;
        }
    }
    output.close();
}

void logic(){

    std::vector<Ride> rides;
    Info info{};
    rides = readRides("b_should_be_easy.in", info);
    int ticks = info.rides;
    std::vector<Car*> cars{};
    for(int i = 0; i < info.vehicles; i++) cars.push_back(new Car());


    for(int currentTick = 0; currentTick < ticks; currentTick++){
        for(Ride & r : rides) if(r.available) if(r.timeFinish <= currentTick) r.available = false;
        for(Car * c : cars){
            if(c->status == 0){
                std::vector<Ride*> possibleRides{};
                for(Ride & r : rides) if(r.available){
                    int totalTime = 0;
                    totalTime += travellingTime(c->position, r.goFrom);
                    if(totalTime + currentTick < r.timeStart) totalTime += (totalTime + currentTick);// - (r.timeStart - totalTime - 1);
                    totalTime += travellingTime(r.goFrom, r.goTo);
                    if(currentTick + totalTime < r.timeFinish){
                        r.endTimeTemp = currentTick + totalTime;
                        possibleRides.push_back(&r);
                    }
                }

                if(!possibleRides.empty()) {
                    // choosing the best ride[will be optimised]
                    std::sort(possibleRides.begin(), possibleRides.end(), [](Ride *ride1, Ride *ride2) {
                        return ride1->endTimeTemp <= ride2->endTimeTemp;
                    });

                    Ride * chosenRide = possibleRides[0];
                    chosenRide->available = false;
                    c->takenRides.push_back(chosenRide->id);
                    c->currentRide = chosenRide->id;
                    c->status = 1;

                    processMove(c, currentTick, rides);
                }
            }

            else{
                processMove(c, currentTick, rides);
            }
        }
    }
    writeRides("output_B.txt", cars);


}

