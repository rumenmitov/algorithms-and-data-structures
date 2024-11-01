#include "WindGauge.h"

#include <iostream>

// Constructor
WindGauge::WindGauge(int period) : period(period) {}

// Destructor
WindGauge::~WindGauge() {}

// Methods
void WindGauge::currentWindSpeed(int speed) {
    if ( static_cast<int>(history.size()) == period ) history.pop_front();

    history.push_back(speed);
};

int WindGauge::highest() const {
    int max = *( history.cbegin() );
    for (int speed : history) {
        if (speed > max) max = speed;
    }

    return max;
}

int WindGauge::lowest() const {
    int min = *( history.cbegin() );
    for (int speed : history) {
        if (speed < min) min = speed;
    }

    return min;
};

int WindGauge::average() const {
    int total_sum = 0;
    for (int speed : history) {
        total_sum += speed;
    }

    return total_sum / history.size();
};

// Dump method to print
void WindGauge::dump(const WindGauge& wg) {
    std::cout << "Lowest: " << wg.lowest() << std::endl;
    std::cout << "Highest: " << wg.highest() << std::endl;
    std::cout << "Average: " << wg.average() << std::endl;
}

