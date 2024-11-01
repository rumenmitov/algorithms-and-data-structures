#include "BST.h"


template <class T>
void BSTree<T>::left_rotate() {
    if (btree.left == nullptr) return;

    BSTree<T>* parent = btree.parent;
    BSTree<T>* new_root = btree.left;
    BSTree<T>* swap_node = btree.left->btree.right;

    new_root->btree.right = this;
    btree.parent = new_root;

    btree.right = swap_node;

    btree = new_root->btree;
    btree.parent = parent;
}


template <class T>
void BSTree<T>::right_rotate() {
    if (btree.right == nullptr) return;

    BSTree<T>* parent = btree.parent;
    BSTree<T>* new_root = btree.right;
    BSTree<T>* swap_node = btree.right->btree.left;

    new_root->btree.right = this;
    btree.parent = new_root;

    btree.right = swap_node;

    btree = new_root->btree;
    btree.parent = parent;
}


template <class T>
void BSTree<T>::recolorize() {
    btree.red ^= 0;
}


template <class T>
void BSTree<T>::insert(const T& val) {
    BSTree* new_el = new BSTree<T>(val);
    new_el->btree.red = 1;

    if (val > btree.val) {

        if (btree.right == nullptr) {
            btree.right = new_el;
            new_el->btree.parent = this;
            new_el->fix_insertion();

        } else btree.right->insert(val);

    } else {

        if (btree.left == nullptr) {
            btree.left = new_el;
            new_el->btree.parent = this;
            new_el->fix_insertion();

        } else btree.left->insert(val);

    }

}

template <class T>
void BSTree<T>::fix_insertion() {
    BSTree<T>* parent = btree.parent;

    // BST Properties are kept
    if (parent == nullptr) {
        btree.red &= 0;
        return;
    } 
    if (!parent->btree.red) return;


    BSTree<T>* grandparent = btree.parent->btree.parent;
    

    // INFO: Case 0 - No Uncle
    // INFO: Case 1 - Red Uncle
    // INFO: Case 2 - Black Uncle

    if (grandparent->btree.right == parent) {
        // INFO: Coming from right subtree.
        if (!grandparent->btree.left) {
            grandparent->left_rotate();
            if (parent == btree.parent) recolorize();
            return parent->fix_insertion();
        }

        if (grandparent->btree.left->btree.red) {
            grandparent->btree.left->recolorize();
            parent->recolorize();
            return grandparent->fix_insertion();
        } else {
            grandparent->left_rotate();
            parent->recolorize();
            grandparent->recolorize();
            recolorize();
        }

    } else {
        // INFO: Coming from left subtree.
        if (!grandparent->btree.right) {
            grandparent->right_rotate();
            if (parent == btree.parent) recolorize();
            return parent->fix_insertion();
        }

        if (grandparent->btree.right->btree.red) {
            grandparent->btree.right->recolorize();
            parent->recolorize();
            return grandparent->fix_insertion();
        } else {
            grandparent->right_rotate();
            parent->recolorize();
            grandparent->recolorize();
            recolorize();
        }

    }
}


template <class T>
BSTree<T>::BSTree(const std::vector<T>& v) {
    btree.val = v[0];

    for (size_t i = 1; i < v.size(); i++) {
        insert(v[i]);
    }
}

template <class T>
BSTree<T>::BSTree() {};


template <class T>
BSTree<T>::BSTree(const T& val) {
    btree.val = val;
}


template <class T>
std::vector<T> BSTree<T>::to_list() const {
    std::vector<T> res;

    if (btree.left != nullptr) {
        for (T val : btree.left->to_list()) res.push_back(val);
    }

    res.push_back(btree.val);

    if (btree.right != nullptr) {
        for (T val : btree.right->to_list()) res.push_back(val);
    }

    return res;
}


template <class T>
BSTree<T>::~BSTree() {};


template class BSTree<int>;
