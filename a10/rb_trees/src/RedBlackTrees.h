#pragma once

#include <vector>


enum Color { RED, BLACK };

struct Node {
  int data = 0;
  Color color = RED;
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
};

/**
 * @brief Red Black Tree root.
 */
class RedBlackTree {

public:
  // Default constructor
  RedBlackTree();

  // Default destructor
  ~RedBlackTree();


  /**
   * Inserts integer into red-black tree.
   * 
   * @param int
   * 
   * @return void
   */
  void insertRB(int);


  /**
   * @brief Deletes node.
   * 
   * @param Node*&
   * 
   * @return void
   */
  void deleteRB(Node*&);


  /**
   * @brief Finds predecessor of node.
   * 
   * @param const Node*&
   * 
   * @return Node*
   */
  Node* predecessor(const Node*&);


  /**
   * @brief Finds successor of node.
   * 
   * @param const Node*&
   * 
   * @return Node*
   */
  Node* successor(const Node*&);


  /**
   * @brief Finds minimum element in the tree.
   * 
   * @return Node*
   */
  Node* getMinimum(void);


  /**
   * @brief Finds maximum element in the tree.
   * 
   * @return Node*
   */
  Node* getMaximum(void);


  /**
   * @brief Returns node with the integer value.
   * 
   * @param int
   * 
   * @return Node*
   */
  Node* search(int);


  /**
   * @brief Sorts elements in ascending order.
   *
   * @return std::vector<int>
   */
  std::vector<int> to_list_asc();


protected:


  /**
   * @brief Fixes insertion into RB Tree from the specified node.
   *
   * @param Node*&
   *
   * @return void
   */
  void fix_insertion(Node*&);
  

  /**
   * @brief Performs left rotation on node.
   * 
   * @param Node*&
   * 
   * @return void
   */
  void rotateLeft(Node*&);


  /**
   * @brief Performs right rotation on node.
   * 
   * @param Node*&
   * 
   * @return void
   */
  void rotateRight(Node*&);

  
  /**
   * @brief Changes color of node.
   *
   * @param Node*&
   *
   * @return void
   */
  void recolorize(Node*&);


  /**
   * @brief Replaces specified node with another.
   *
   * @param Node*&
   * @param Node*&
   *
   * @return void
   */
  void transplant(Node*&, Node*&);


  /**
   * @brief Fixes deletion double-black case.
   *
   * @param Node*&
   *
   * @return void
   */
  void fix_deletion(Node*&);
  
  
  /**
   * @brief Traverses first left subtree, then root, then right subtree.
   *
   * @param const Node*&
   *
   * @return std::vector<int>
   */
  std::vector<int> in_order_traversal(Node*&);

private:
  Node* root;

};

