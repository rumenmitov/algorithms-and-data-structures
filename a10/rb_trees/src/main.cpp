#include <cassert>
#include <iostream>

#include "RedBlackTrees.h"

using namespace std;
int main(int argc, char* argv[]) {

  cout << "Testing RB insertion...";
  std::vector<int> insertion_solution { 1, 5, 6, 7, 8 ,9 };
  RedBlackTree root;
  
  for (auto rit = insertion_solution.crbegin();
       rit != insertion_solution.crend(); rit++)
    {
      root.insertRB(*rit);
    }
  
  assert(insertion_solution == root.to_list_asc());
  cout << "passed\n";

  try {
    Node* empty_node = nullptr;
    root.deleteRB(empty_node);
  } catch (const char e[]) {
    cout << "Error: " << e << endl;
  }

  cout << "Testing RB deletion...";

  const size_t len = insertion_solution.size();
  for (size_t i = 0; i < len; i++) {
    Node* max = root.getMaximum();
    try {
      root.deleteRB(max);
    } catch (const char e[]) {
      cout << "Error: " << e << endl;
    }

    insertion_solution.pop_back();
    assert(insertion_solution == root.to_list_asc());
  }

  cout << "passed\n";
  
  Node* max = root.getMaximum();
  try {
    root.deleteRB(max);
  } catch (const char e[]) {
    cout << "Error: " << e << endl;
  }

  return 0;
}
