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
const int SIM_TIME = 20;

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

    for (int time = 1; time <= SIM_TIME; time++) {
        cout << "Time: " << time << endl;

        for (int i = 0; i < NUM_LANES; i++) {
            auto& lane = lanes[i];

            if (lane.empty()) {
                if (rand() % 2 == 0) {
                    lane.push_back(Car());
                    cout << "Lane " << i+1 << " Joined (empty lane)\n";
                }
            } else {
                double r = (double)rand() / RAND_MAX;
                if (r < 0.5) {
                    lane.pop_front();
                    cout << "Lane " << i+1 << " Paid\n";
                } else {
                    lane.push_back(Car());
                    cout << "Lane " << i+1 << " Joined\n";
                }
            }
        }

        for (int i = 0; i < NUM_LANES; i++) {
            cout << "Lane " << i+1 << " Queue:\n";
            if (lanes[i].empty()) cout << "    Empty\n";
            else for (auto& c : lanes[i]) { cout << "    "; c.print(); cout << endl; }
        }
        cout << endl;
    }

    return 0;
}