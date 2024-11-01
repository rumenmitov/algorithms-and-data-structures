#include <cstring>
#include <cstdlib>
#include <iostream>

#include "Stack.h"
#include "Queue.h"

using namespace std;
int main(void) {


    cout << endl;
    cout << "  /-----------------/" << endl;
    cout << " / Problem 9.1 (a) /" << endl;
    cout << "/-----------------/" << endl;
    cout << endl;

    cout << 
        "Enter integer for size of stack (-1 for unlimited size): ";

    int max_size;
    cin >> max_size;
    getchar();

    Stack<int>* my_stack = nullptr;

    if (!max_size || max_size == -1) {
        cout << "Creating unlimited stack..." << endl;
        my_stack = new Stack<int>;
    } else {
        cout << "Creating stack with max_size = " << max_size << "..." << endl;
        my_stack = new Stack<int>(max_size);
    }

    do {
        cout 
            << "Enter integer value to push to the stack "
            << "(`q` empties the stack and quits): ";

        char* input = new char[255];

        cin.getline(input, 10, '\n');

        if (strcmp(input, "q") == 0) {
            goto QUEUES;
        }

        try {
            my_stack->push(atoi(input));
        } catch (const char* e) {
            cout << "Error: " << e << endl;
        }

    } while (true);



QUEUES:
    cout << "Exiting...\nPopping stack:\n";
    while ( !my_stack->isEmpty() ) {
        cout << my_stack->pop() << " ";
    }
    cout << endl;

    cout << endl;
    cout << "  /-----------------/" << endl;
    cout << " / Problem 9.1 (b) /" << endl;
    cout << "/-----------------/" << endl;
    cout << endl;


    Queue<double> q;

    do {
        cout << "Enter floating point value to enqueue "
            << "(`q` empties the queue and quits): ";

        char* input = new char[255];

        cin.getline(input, 255, '\n');

        if (strcmp(input, "q") == 0) {
            goto END;
        }

        try {
            q.enqueue( strtod(input, nullptr) );
        } catch (const char* e) {
            cout << "Error: " << e << endl;
        }

    } while (true);


END:
    cout << "Exiting...\nDequeueing from queue:\n";
    while ( !q.isEmpty() ) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
    cout << endl;

    return 0;
}
