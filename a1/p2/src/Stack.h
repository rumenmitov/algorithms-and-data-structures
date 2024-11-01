#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <cassert>
#include <ostream>

template <class T>
class Stack {
    private:
        unsigned int size;
        unsigned int top;
        T* elements;

        // Extend stack capacity
        void extend(void) {
            T* extended_stack = new T[size * 2];

            for (unsigned int i = 0; i < size; ++i) {
                extended_stack[i] = elements[i];
            }

            size *= 2;
            delete[] elements;

            elements = extended_stack;
        }

    public:
        // Constructors
        Stack<T>() {
            size = 10;
            top = -1;

            elements = new T[size];
        }

        Stack<T>(const Stack& s) {
            size = s.size;
            top = s.top;

            elements = new T[size];

            for (unsigned int i = 0; i <= s.top; ++i) {
                elements[i] = s.elements[i];
            }

        }

        Stack<T>(int size) {
            this->size = size;
            top = -1;

            elements = new T[this->size];
        }

        // Destructor
        ~Stack<T>() {
            delete[] elements;
        }

        // Push to stack
        bool push(T element) {
            if (++top == size) extend();

            elements[top] = element;

            return true;
        }

        // Pop from stack
        bool pop(T& out) {
            if (top < 0) return false;

            out = elements[top--];
            return true;
        }

        // Peek top element
        T back(void) const {
            assert(top >= 0);
            return elements[top];
        }

        // Get number of elements in stack
        int getNumEntries(void) const {
            if (top < 0) return 0;
            return top + 1;
        }

        // Override output
        friend std::ostream& operator<<(std::ostream& f, const Stack<T>& s) {
            f << "[ ";

            for (int i = s.top; i >= 0; --i) {
                f << s.elements[i] << " ";
            }

            f << "]";

            return f;
        }
};

#endif
