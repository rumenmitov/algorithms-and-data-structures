#ifndef __STACK_H
#define __STACK_H

template <class T>
class Stack {
    public:
        // Default constructor
        Stack();

        // Constructor creates stack with specified max-size
        Stack(int);

        // Default destructor
        ~Stack();

        // Pushes element to the top of Stack
        // Throws if max-size had been set and is exceeded
        void push(T);

        // Removes element from top of stack and returns it
        // Throws if stack is empty
        T pop();

        // Returns true if stack is empty
        bool isEmpty () const;

    private:
        struct StackNode {
            T data;
            StackNode* next;
            StackNode* prev;
        };

        StackNode* top = nullptr;
        int size = -1;
        int current_size = -1;

};



#endif
