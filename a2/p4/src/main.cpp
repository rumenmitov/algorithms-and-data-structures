#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 2.4 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    // Initialize vector with numbers from 1 to 30
    vector<int> v;
    for (int i = 1; i <= 30; i++) {
        v.push_back(i);
    }

    // Push 5 to back of vector and reverse
    v.push_back(5);
    reverse(v.begin(), v.end());

    // Print reversed vector
    cout << "Reversed vector: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    // Replace all occurences of 5 with 129
    replace(v.begin(), v.end(), 5, 129);

    // Print final vector
    cout << "Vector after replacements: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    return 0;
}
