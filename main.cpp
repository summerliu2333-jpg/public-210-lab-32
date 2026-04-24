//COMSC-210-5068, Lab 33, Yang Liu
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Car.h"
using namespace std;

const int NUM_LANES = 4;
const int INITIAL_CARS = 2;

const double LEAVE_PROB = 0.46;
const double JOIN_PROB = 0.39;
const double SWITCH_PROB = 0.15;

int main() {
    srand(time(0));

    vector<deque<Car>> lanes(NUM_LANES);

    lanes[0].push_back(Car());

    cout << "M2: 4 lanes created successfully\n";

    return 0;
}