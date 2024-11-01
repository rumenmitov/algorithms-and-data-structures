#include "Stack.h"


template <class T>
Stack<T>::Stack() {};

template <class T>
Stack<T>::Stack(int new_size) : size(new_size) {};

template <class T>
Stack<T>::~Stack() {
    while ( !isEmpty() ) pop();
};

template <class T>
void Stack<T>::push(T x) {
    if (size > -1 && current_size >= size - 1) {
        throw "Buffer overflow when trying to push to stack!";
    }

    current_size++;

    StackNode* newEl = new StackNode;
    newEl->data = x;
    newEl->next = nullptr;
    newEl->prev = nullptr;

    if (top == nullptr) {
        top = newEl;
        return;
    }

    newEl->prev = top;

    top->next = newEl;
    top = newEl;
}

template <class T>
T Stack<T>::pop() {
    if (isEmpty()) throw "Buffer underflow when trying to pop from stack!";

    current_size--;

    T val = top->data;

    StackNode* marker = top;

    top = top->prev;

    delete marker;

    return val;
}

template<class T> 
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template class Stack<int>;
template class Stack<double>;
