//COMSC-210-5068, Lab 33, Yang Liu
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Car.h"
using namespace std;

const int NUM_LANES = 4;
const int INIT_PER_LANE = 2;

const double LEAVE_PROB = 0.46;
const double JOIN_PROB = 0.39;
const double SWITCH_PROB = 0.15;

int main() {
    srand(time(0));

    vector<deque<Car>> lanes(NUM_LANES);

    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INIT_PER_LANE; j++) {
            lanes[i].push_back(Car());
        }
    }

    cout << "Initial queue:" << endl;
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i+1 << ":" << endl;
        for (auto& car : lanes[i]) {
            cout << "    ";
            car.print();
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}