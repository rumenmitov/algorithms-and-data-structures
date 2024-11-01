#include <climits>

#include "HashMap.h"
#include "Utils.h"


HashTable::HashTable() {
   maxSize = INT_MAX; 
   currentSize = 0;
   arr = new Node*[maxSize];
   prime_modulo = maxSize;

   while (!is_prime(prime_modulo)) prime_modulo--;
}


HashTable::~HashTable() {
    unsigned int i = 0;

    while (!isEmpty()) {
        if (arr[i]) {
            delete arr[i];
            currentSize--;
        }

        i++;
    }

    delete arr;
}


int HashTable::hashCode(int key, int probe) {
    // INFO: I selected h' = key % prime_modulo, because 
    // the prime_modulo is a prime number close to the maximum size of the 
    // hash table thus resulting in 1/m chances of collisions, where
    // m = max size of truth table.
    return ( (key % prime_modulo) + probe) % maxSize;
}


void HashTable::insertNode(int key, int value) {
    if (currentSize == maxSize) throw "Hash table is full!";

    unsigned int i = 0;
    int hash = 0;

    do {
        hash = hashCode(key, i);
        i++;
    } while (arr[hash]);

    arr[hash] = new Node(key, value);
}


int HashTable::get(int key) {
    unsigned int i = 0;
    int hash = 0;

    do {
        hash = hashCode(key, i);
        i++;
    } while (arr[hash]->key != key);

    return arr[hash]->value;
}


bool HashTable::isEmpty() const {
    if (currentSize == 0) return true;
    else return false;
}
