#ifdef DEBUG

#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>

#include "HashMap.h"

using namespace std;

#endif


int main(int argc, char* argv[]) {

  #ifdef DEBUG
    cout << "Testing hash table...";

    srand( time(nullptr) );

    HashTable hash_table;

    for (int k = 0; k < HashTable::DEFAULT_MAX_SIZE; k++) {
        int val = rand() * 100;

        try {
            hash_table.insertNode(k, val);
        } catch (char e[]) {
            cerr << "Error: " << e << endl;
        }

        assert(val == hash_table.get(k));
    }

    cout << "passed." << endl;

    #endif

    return 0;
}
