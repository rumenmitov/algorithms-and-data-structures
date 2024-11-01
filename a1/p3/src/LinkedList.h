#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <iostream>

#include <cassert>
#include <ostream>

// NOTE: Using namespace as to not export this struct.
namespace Node {
    template<typename T>
        struct Node {
            T val;
            Node<T>* next;
            Node<T>* prev;
        };
}

// NOTE: LinkedList class is responsible for keeping meta-data for the list.
template <class T>
class LinkedList {
    private:
        Node::Node<T>* head;
        Node::Node<T>* tail;
        unsigned int len = 0;

    public:
        // Constructors
        LinkedList<T>() {
            head = tail = nullptr;
            len = 0;
        }

        LinkedList<T>(const LinkedList<T>& other) {
            if (!other.length()) return;

            Node::Node<T>* cursor = other.head;

            while (cursor != other.tail) {
                this->push_back(cursor->val);
                cursor = cursor->next;
            }

            this->push_back(other.tail->val);
        }

        // Destructor
        ~LinkedList(void) {
            if (len == 0) return;

            while (len > 0) pop_back();
        }

        // Peeking
        T peek_front(void) const {
            assert(len != 0);
            return head->val;
        }

        T peek_back(void) const {
            assert(len != 0);
            return tail->val;
        }

        // Popping
        T pop_front(void) {
            assert(len != 0);
            T val = head->val;

            Node::Node<T>* cursor = head;

            if (len > 1) head = head->next;

            delete cursor;
            len--;

            return val;
        }

        T pop_back(void) {
            T val = tail->val;

            Node::Node<T>* cursor = tail;

            if (len > 1) tail = tail->prev;

            delete cursor;
            len--;

            return val;
        }

        // Pushing 
        void push_front(T val) {
            Node::Node<T>* newEl = new Node::Node<T>;
            newEl->val = val;


            if (len == 0) {
                head = tail = newEl;
                len++;
                return;
            }

            head->prev = newEl;
            newEl->next = head;

            head = newEl;

            len++;
        }

        void push_back(T val) {
            Node::Node<T>* newEl = new Node::Node<T>;
            newEl->val = val;
            

            if (len == 0) {
                head = tail = newEl;
                len++;
                return;
            }

            tail->next = newEl;
            newEl->prev = tail;

            tail = newEl;

            len++;
        }

        unsigned int length(void) const {
            return len;
        }

        friend std::ostream& operator<<
            (std::ostream& f, const LinkedList<T>& l) {

                if (l.length() == 0) f << "[ ]";
                else {
                    Node::Node<T>* cursor = l.head;

                    f << "[ ";
                    while (cursor != l.tail) {
                        f << cursor->val << " ";
                        cursor = cursor->next;
                    }
                    f << l.tail->val << " ";
                    f << "]";
                }

                return f;
        }

};


#endif
