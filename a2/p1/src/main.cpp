#include <iostream>
#include <fstream>
#include <list>

using namespace std;

template <class T>
void move_first_element_to_end(list<T>& l) {
    int tmp = l.front();
    l.pop_front();
    l.push_front(tmp);
}

int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 2.1 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    // Initialize lists
    list<int> A;
    list<int> B;

    // Get inputs
    int input;
    while (true) {
        cin >> input;

        if (input <= 0) break;

        A.push_back(input);
        B.push_front(input);
    }

    // Print lists
    cout << "List A: ";
    for (int num : A) {
        cout << num << " ";
    }

    ofstream file("listB.txt");

    file << "List B: ";
    for (int num : B) {
        file << num << " ";
    }

    file.close();

    cout << endl;

    // Move first element to end
    move_first_element_to_end<int>(A);
    move_first_element_to_end<int>(B);

    // Print elements again
    cout << "List A: ";
    list<int>::const_iterator last_el_in_A = A.cend();
    last_el_in_A--;
    for (list<int>::const_iterator it = A.cbegin(); it != last_el_in_A; it++) {
        cout << *it << ",";
    }
    cout << *last_el_in_A << endl;

    cout << "List B: ";
    list<int>::const_iterator last_el_in_B = B.cend();
    last_el_in_B--;
    for (list<int>::const_iterator it = B.cbegin(); it != last_el_in_B; it++) {
        cout << *it << ",";
    }
    cout << *last_el_in_B << endl;

    // Merge lists B into A
    A.merge(B);

    // Sort
    A.sort([](int a, int b) -> bool {
            if (a <= b) return true;
            else return false;
    });

    cout << "Merged List: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}

