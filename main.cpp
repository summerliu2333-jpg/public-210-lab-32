//COMSC-210-5068, Lab 32, Yang Liu
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL_CARS = 2;
const double LEAVE_PROB = 0.55;

int main() {
    srand(time(0));

    deque<Car> tollLane;

    for (int i = 0; i < INITIAL_CARS; i++) {
        tollLane.push_back(Car());
    }

    cout << "Initial queue:" << endl;
    for (auto& car : tollLane) {
        car.print();
        cout << endl;
    }
    cout << endl;

    return 0;
}