#pragma once

/**
 * @brief Stores key value pair.
*/
class Node {

    public:

        Node() {}
        Node(int key, int value) : key(key), value(value) {}
        ~Node() {}

        int key;
        int value;
};


/**
 * @brief Storage for key-value nodes, using open-addressing.
*/
class HashTable {


    public:

        static const unsigned int DEFAULT_MAX_SIZE = 1000;


        // Default constructor stores by default DEFAULT_MAX_SIZE 
        // number of nodes.
        HashTable();

        // Default destructor
        ~HashTable();

       /**
        * @brief Returns the hash code corresponding to the key identifier.
        * 
        * @param int
        * 
        * @return int
       */
       int hashCode(int, int);


       /**
        * @brief Inserts key-value node into the hash map.
        * 
        * @param int
        * @param int
        * 
        * @return void
       */
       void insertNode(int, int);


       /**
        * @brief Retrieves value corresponding to the key.
        * 
        * @param int
        * 
        * @return int
       */
       int get(int);


       /**
        * @brief Returns true if hash map is empty, false otherwise.
        * 
        * @return bool
       */
       bool isEmpty(void) const;
        

    private:

       Node** arr;
       int maxSize;
       int prime_modulo;
       int currentSize;
};
