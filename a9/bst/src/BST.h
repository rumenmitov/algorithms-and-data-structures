#ifndef __BST_H_
#define __BST_H_

#include <vector>

template <class T>
class BSTree {

    public:
        // Default constructor, sets value to 0
        BSTree();

        // Constructor, sets given value
        BSTree(const T&);

        // Constructor, inserts vector
        BSTree(const std::vector<T>&);

        ~BSTree();

        // Perform in-order DFS to produce sorted list of data.
        std::vector<T> to_list() const;



    private:
        struct BTree {
            T val = 0;
            unsigned char red = 0;

            BSTree<T>* parent = nullptr;
            BSTree<T>* left = nullptr;
            BSTree<T>* right = nullptr;
        } btree;

        // Inserts element
        void insert(const T&);

        // Fixes insertion from current node upwards
        void fix_insertion();

        // Rotates down
        void left_rotate();
        void right_rotate();

        // Toggles color bit
        void recolorize();
};

#endif
