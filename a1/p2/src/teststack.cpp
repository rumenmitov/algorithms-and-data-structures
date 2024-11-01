#include <cassert>
#include <iostream>

#include "Stack.h"


using namespace std;
int main(void) {
    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 1.2 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    Stack<int> empty_stack;
    cout << "Empty stack:\n" << empty_stack << endl << endl;

    Stack<int> sized_stack(5);
    sized_stack.push(1);
    sized_stack.push(2);
    sized_stack.push(3);
    sized_stack.push(4);
    sized_stack.push(5);
    cout << "Fixed size stack (size = 5):\n" << sized_stack << endl << endl;

    sized_stack.push(6);
    cout << "Fixed size stack extended:\n" << sized_stack << endl << endl;

    Stack<int> copied_stack(sized_stack);
    cout << "Copied stack:\n" << copied_stack << endl << endl;

    cout << "Number of entries: " 
        << copied_stack.getNumEntries() 
        << "; Last element: " 
        << copied_stack.back() 
        << endl
        << endl;

    while (copied_stack.getNumEntries()) {
        int popped;
        assert(copied_stack.pop(popped));
        cout << "Popped out: " << popped << endl;
    }

    return 0;
}
