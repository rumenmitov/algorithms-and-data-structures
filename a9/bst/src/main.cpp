#include <iostream>

#include "BST.h"

using namespace std;


int main(void) {

    vector<int> arr1 { 1, 2, 3, 4, 5};
    vector<int> arr2 { 5, 4, 3, 2, 1 };
    vector<int> arr3 { 3, 4, 1, 5, 2 };

    cout << endl;
    cout << "  /-----------------/" << endl;
    cout << " /   Problem 9.2   /" << endl;
    cout << "/-----------------/" << endl;
    cout << endl;

    cout << "Ascendingly sorted array:\n";
    cout << "Input: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    cout << "Output: ";
    BSTree<int> bst1(arr1);
    for (int x : bst1.to_list()) cout << x << " ";
    cout << endl;

    cout << endl;
    cout << "Descendingly sorted array:\n";
    cout << "Input: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    cout << "Output: ";
    BSTree<int> bst2(arr2);
    for (int x : bst2.to_list()) cout << x << " ";
    cout << endl;

    cout << endl;
    cout << "Unsorted array:\n";
    cout << "Input: ";
    for (int x : arr3) cout << x << " ";
    cout << endl;
    cout << "Output: ";
    BSTree<int> bst3(arr3);
    for (int x : bst3.to_list()) cout << x << " ";
    cout << endl;

    return 0;
}
