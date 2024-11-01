#include <iostream>
#include "WindGauge.h"

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 2.3 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    // Initializing object
    WindGauge wg;

    // Adding speeds and dumping
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(12);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(15);

    WindGauge::dump(wg);
    cout << endl;

    // Adding more entries and dumping
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(17);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(20);
    wg.currentWindSpeed(17);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(20);

    WindGauge::dump(wg);
    cout << endl;

    return 0;
}
