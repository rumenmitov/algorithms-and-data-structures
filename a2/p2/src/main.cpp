#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 2.2 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    // Initialize deque
    deque<float>A;

    // Get input
    float input;
    cin >> input;

    while (input != 0) {
        if (input > 0) A.push_back(input);
        else A.push_front(input);
        cin >> input;
    }

    // Print elements
    for (float num : A) {
        cout << num << " ";
    }
    cout << endl;

    // Insert 0 between negatives and positives
    for (deque<float>::const_iterator it = A.cbegin(); it != A.cend(); it++) {
        if ( *(it + 1) > 0 ) {
            A.insert(it + 1, 0);
            break;
        }
    }

    // Print deque
    deque<float>::const_iterator last_el = A.cend();
    last_el--;
    for (deque<float>::const_iterator it = A.cbegin(); it != last_el; it++) {
        cout << *it << ";";
    }
    cout << *last_el << endl;

    return 0;
}
