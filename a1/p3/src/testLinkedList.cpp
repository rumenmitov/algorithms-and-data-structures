#include <iostream>

#include "LinkedList.h"

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 1.3 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    LinkedList<string> list;
    cout << "My list: " << list << endl;
    list.push_back( string("hello") );
    list.push_back( string("world") );
    cout << "After pushing back: " << list << endl;
    list.push_front( string("says") );
    list.push_front( string("list") );
    list.push_front( string("my") );
    cout << "After pushing front: " << list << endl << endl;

    cout << "Number of elements: " << list.length() << endl;
    cout << "First entry: " << list.peek_front() << endl;
    cout << "Last entry: " << list.peek_back() << endl << endl;

    LinkedList<string> copied_list(list);
    cout << "Copied list: " << copied_list << endl;
    cout << "Popping 3 elements from the back:\n";
    for (int i = 0; i < 3; ++i) {
        cout << copied_list.pop_back() << endl;
    }
    cout << endl;

    cout << "Popping last 2 elements from the front:\n";
    for (int i = 0; i < 2; ++i) {
        cout << copied_list.pop_front() << endl;
    }
    cout << endl;

    return 0;
}
