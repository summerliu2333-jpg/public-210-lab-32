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
        cout << "    ";
        car.print();
        cout << endl;
    }
    cout << endl;

    int timeStep = 1;

    while (!tollLane.empty()) {
        double r = (double)rand() / RAND_MAX;

        cout << "Time: " << timeStep << " Operation: ";

        if (r < LEAVE_PROB) {
            Car paidCar = tollLane.front();
            tollLane.pop_front();
            cout << "Car paid: ";
            paidCar.print();
        }
        else {
            Car newCar;
            tollLane.push_back(newCar);
            cout << "Joined lane: ";
            newCar.print();
        }

        cout << "\nQueue:\n";
        if (tollLane.empty()) {
            cout << "    Empty\n";
        } else {
            for (auto& car : tollLane) {
                cout << "    ";
                car.print();
                cout << endl;
            }
        }
        cout << endl;

        timeStep++;
    }

    return 0;
}