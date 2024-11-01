#include <vector>

#include "RedBlackTrees.h"


RedBlackTree::RedBlackTree() : root(nullptr) {}


RedBlackTree::~RedBlackTree() {
  while (root) {
    Node* marker = getMinimum();
    deleteRB(marker);
  }
}


void RedBlackTree::insertRB(int x) {
  Node* new_el = new Node;
  new_el->data = x;

  if (root == nullptr) {
    root = new_el;
    root->color = BLACK;
    return;
  }

  Node* cur_root = root;
  while (true) {
    if (x > cur_root->data) {

      if (cur_root->right == nullptr) {
	cur_root->right = new_el;
	new_el->parent = cur_root;
	fix_insertion(new_el);
	break;
      } else {
	cur_root = cur_root->right;
	continue;
      }

    } else {
     
      if (cur_root->left == nullptr) {
	cur_root->left = new_el;
	new_el->parent = cur_root;
	fix_insertion(new_el);
	break;
      } else {
	cur_root = cur_root->left;
	continue;
      }

    }
  }

  while (root->parent != nullptr) root = root->parent;
  root->color = BLACK;
}


void RedBlackTree::deleteRB(Node*& n) {
  if (!root) throw "Cannot delete from an empty tree!";
  if (!n) throw "Cannot remove empty node!";
  
  Node* _successor = nullptr;
  Color original_color = n->color;

  if (!n->right && !n->left) {
    transplant(n, _successor);
    goto DELETE;
  }

  if (!n->right) {
    transplant(n, n->left);
    _successor = n->left;
    original_color = n->color;
  } else if (!n->left) {
    transplant(n, n->right);
    _successor = n->right;
    original_color = n->color;
  } else {
    
    _successor = successor((const Node*&) n);
    original_color = _successor->color;

    // INFO: Handling case where _successor->parent = n
    if (_successor->parent == n) {
      transplant(n, _successor);
    } else {
      transplant(_successor, _successor->right);
      _successor->right = n->right;
      n->right->parent = _successor;
    }
  
    _successor->left = n->left;
    n->left->parent = _successor;
    transplant(n, _successor);
  }

  _successor->color = n->color;

 DELETE:
  if (original_color == BLACK && _successor)
    fix_deletion(_successor);
}


Node* RedBlackTree::predecessor(const Node*& cur) {
  if (cur == nullptr || cur->right == nullptr) return nullptr;

  Node* bigger_root = cur->right;

  for (; bigger_root->left != nullptr; bigger_root = bigger_root->left) {}

  return bigger_root;
}


Node* RedBlackTree::successor(const Node*& cur) {
  if (cur == nullptr || cur->right == nullptr) return nullptr;

  Node* bigger_root = cur->right;

  for (; bigger_root->left != nullptr; bigger_root = bigger_root->left) {}

  return bigger_root;
}


Node* RedBlackTree::getMinimum(void) {
  if (root == nullptr) return nullptr;

  Node* ptr = root;
  for (; ptr->left != nullptr; ptr = ptr->left) {}

  return ptr;
}
    

Node* RedBlackTree::getMaximum(void) {
  if (root == nullptr) return nullptr;

  Node* ptr = root;
  for (; ptr->right != nullptr; ptr = ptr->right) {}

  return ptr;
}


Node* RedBlackTree::search(int needle) {
  Node* cur = root;
  while (cur != nullptr && needle != cur->data) {
    if (needle < cur->data) cur = cur->left;
    else cur = cur->right;
  }

  return cur;
}


std::vector<int> RedBlackTree::to_list_asc() {
  return in_order_traversal(root);
}
  

void RedBlackTree::fix_insertion(Node*& n) {

  Node* parent = n->parent;

  // BST Properties are kept
  if (parent == nullptr) {
    n->color = BLACK;
    return;
  } 

  if (parent->color == BLACK) return;


  Node* grandparent = parent->parent;
  if (grandparent == nullptr) {
    parent->color = BLACK;
    return;
  }    

  // INFO: Case 0 - No Uncle
  // INFO: Case 1 - Red Uncle
  // INFO: Case 2 - Black Uncle

  if (grandparent->right == parent) {
    // INFO: Coming from right subtree.
    if (!grandparent->left) {
      rotateLeft(grandparent);
      recolorize(n);
      return fix_insertion(parent);
    }

    if (grandparent->left->color == RED) {
      recolorize(grandparent->left);
      recolorize(parent);
      return fix_insertion(grandparent);
    } else {
      rotateLeft(grandparent);
      recolorize(parent);
      recolorize(grandparent);
      recolorize(n);
    }

  } else {
    // INFO: Coming from left subtree.
    if (!grandparent->right) {
      rotateRight(grandparent);
      recolorize(n);
      return fix_insertion(parent);
    }

    if (grandparent->right->color == RED) {
      recolorize(grandparent->right);
      recolorize(parent);
      return fix_insertion(grandparent);
    } else {
      rotateRight(grandparent);
      recolorize(grandparent);
      recolorize(parent);
      recolorize(n);
    }

  }
}


void RedBlackTree::rotateLeft(Node*& n) {
  if (n->left == nullptr) return;

  Node* parent = n->parent;
  Node* new_root = n->right;
  Node* swap_node = new_root->left;

  new_root->left = n;
  n->parent = new_root;

  n->right = swap_node;
  swap_node->parent = n;

  if (parent != nullptr) {
    if (parent->left == n) parent->left = new_root;
    else parent->right = new_root;
  }
  
  new_root->parent = parent;
}
                                             
                                             
void RedBlackTree::rotateRight(Node*& n) {
  if (n == nullptr) return;
  if (n->left == nullptr) return;

  Node* parent = n->parent;
  Node* new_root = n->left;
  Node* swap_node = new_root->right;

  new_root->right = n;
  n->parent = new_root;

  n->left = swap_node;
  if (swap_node) swap_node->parent = n;

  if (parent != nullptr) {
    if (parent->left == n) parent->left = new_root;
    else parent->right = new_root;
  }
  
  new_root->parent = parent;
}
                                             

void RedBlackTree::recolorize(Node*& n) {
  switch (n->color) {
    
  case RED:
    n->color = BLACK;
    break;

  case BLACK:
    n->color = RED;
    break;

  default:
    break;
    
  }

}


void RedBlackTree::transplant(Node*& replaced, Node*& replacer) {
  Node* parent = replaced->parent;

  if (replacer) replacer->parent = parent;

  if (parent) {
    if (parent->left == replaced) parent->left = replacer;
    else parent->right = replacer;
  } else {
    root = replacer;
  }
}

void RedBlackTree::fix_deletion(Node*& n) {
  while (n->parent && n->color == RED) {
    // Case 0: Sibling is red.
    // Case 1: Nephews are black.
    // Case 2: Outer nephew is red.
    // Case 3: Inner newphew is red and outer nephew is black.
    
    if (n == n->parent->left) {
      // INFO: Coming from the left subtree.
      if (n->parent->right->color == RED) {
	recolorize(n->parent);
	recolorize(n->parent->right);
	rotateLeft(n->parent);
      }

      Node* sibling = n->parent->right;

      if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
	recolorize(sibling);
	n = n->parent;
      } else if (sibling->right->color == RED) {
	sibling->color = n->parent->color;
	sibling->right->color = BLACK;
	n->parent->color = BLACK;
	rotateLeft(n->parent);
	break;
      } else if (sibling->left->color == RED) {
	recolorize(sibling->left);
	recolorize(sibling);
	rotateRight(sibling);
	sibling = n->parent->right;
      }
    } else {
      // INFO: Coming from right subtree.
      if (n->parent->left->color == RED) {
	recolorize(n->parent->left);
	recolorize(n->parent);
	rotateRight(n->parent);
      }

      Node* sibling = n->parent->right;

      if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
	recolorize(sibling);
	n = n->parent;
      } else if (sibling->left->color == RED) {
	sibling->color = n->parent->color;
	sibling->left->color = BLACK;
	rotateRight(n->parent);
	break;
      } else if (sibling->right->color == RED) {
	recolorize(sibling->right);
	recolorize(sibling);
	rotateLeft(sibling);
	sibling = n->parent->left;
      }
    }
  }

  root->color = BLACK;
}


std::vector<int> RedBlackTree::in_order_traversal(Node*& root) {
  std::vector<int> final_res;

  if (root == nullptr) return final_res;

  for (int x : in_order_traversal(root->left)) final_res.push_back(x);
  final_res.push_back(root->data);
  for (int x : in_order_traversal(root->right)) final_res.push_back(x);

  return final_res;
}
