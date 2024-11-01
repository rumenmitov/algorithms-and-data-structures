#pragma once

#include <cstdint>
#include <vector>
#include <deque>


// Each Node remembers the greatest path from the bottom to itself.
struct Node {
  unsigned int val = 0;
  
  uint64_t greatest_sum = 0;
  std::deque<unsigned int> greatest_path;
};


class Triangle {
 public:
  Triangle();

  // Remembers the greatest path from the bottom and updates the 
  // current node with the greatest child of the node.
  Triangle(const std::vector<std::vector<unsigned int>>&);
  ~Triangle();

  // Returns the solution.
  const Node& get() const;

 private:
  Node** triangle;
  size_t triangle_rows;

  Node get_left_child(size_t, size_t) const;
  Node get_right_child(size_t, size_t) const;
};



