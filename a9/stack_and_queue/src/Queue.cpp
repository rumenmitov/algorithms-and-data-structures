#include "Queue.h"


template <class T>
Queue<T>::Queue() {};

template <class T>
Queue<T>::~Queue() {};


template <class T>
void Queue<T>::enqueue(T x) {
    push_stack.push(x);
}


template <class T>
T Queue<T>::dequeue() {
    if ( !pop_stack.isEmpty() ) return pop_stack.pop();

    if (push_stack.isEmpty()) {
        throw "Buffer underflow when trying to pop from an empty queue!";
    }

    pop_stack.push( push_stack.pop() );

    return pop_stack.pop();
}


template <class T>
bool Queue<T>::isEmpty() const {
    return pop_stack.isEmpty() && push_stack.isEmpty();
}


template class Queue<double>;
