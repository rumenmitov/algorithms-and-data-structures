#ifndef __QUEUE_H
#define __QUEUE_H


#include "Stack.h"

template <class T>
class Queue {
    public:
        // Constructor
        Queue();

        // Destructor
        ~Queue();

        // Adds element to the back of the queue
        void enqueue(T);

        // Removes first element in the queue and returns it
        T dequeue();

        // Returns true if queue is empty
        bool isEmpty() const;


    private:
        Stack<T> push_stack;
        Stack<T> pop_stack;

};

#endif
