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

        vector<Car> switchCar(NUM_LANES);
        vector<int> fromLane(NUM_LANES, -1);

        for (int i = 0; i < NUM_LANES; i++) {
            auto& lane = lanes[i];

            if (lane.empty()) {
                if (rand() % 2 == 0) {
                    Car c;
                    lane.push_back(c);
                    cout << "Lane " << i+1 << " Joined: "; c.print(); cout << endl;
                }
                continue;
            }

            double r = (double)rand() / RAND_MAX;

            if (r < LEAVE_PROB) {
                Car c = lane.front();
                lane.pop_front();
                cout << "Lane " << i+1 << " Paid: "; c.print(); cout << endl;
            }
            else if (r < LEAVE_PROB + JOIN_PROB) {
                Car c;
                lane.push_back(c);
                cout << "Lane " << i+1 << " Joined: "; c.print(); cout << endl;
            }
            else {
                Car c = lane.back();
                lane.pop_back();
                switchCar[i] = c;
                fromLane[i] = i;
                cout << "Lane " << i+1 << " Switched: "; c.print(); cout << endl;
            }
        }

        for (int i = 0; i < NUM_LANES; i++) {
            if (fromLane[i] != -1) {
                int target;
                do {
                    target = rand() % NUM_LANES;
                } while (target == fromLane[i]);
                lanes[target].push_back(switchCar[i]);
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