#include <iostream>
#include <time.h>
#include <set>

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 2.5 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    set<int> rand_nums;
    int num = 0;

    while (rand_nums.size() < 6) {
        // Source: cplusplus.com/reference/cstdlib/rand/
        srand( time(nullptr) );
        num = rand() % 49 + 1;
        rand_nums.insert(num);
    }

    // Set automatically traverses elements in ascending order
    // NOTE: Set organizes keys in ascending order by default
    cout << "Random numbers: ";
    for (int num : rand_nums) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}
