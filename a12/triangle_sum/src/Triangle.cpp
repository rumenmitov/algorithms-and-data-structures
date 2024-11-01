#include "Triangle.h"


Triangle::Triangle(){};


Triangle::Triangle(const std::vector<std::vector<unsigned int>> &table) {

  triangle_rows = table.size();
  triangle = new Node *[triangle_rows];

  for (size_t i = 0; i < table.size(); i++) {
    Node *row = new Node[table[i].size()];

    for (size_t j = 0; j < table[i].size(); j++) {
      Node current{.val = table[i][j],
                   .greatest_sum = table[i][j],
                   .greatest_path = std::deque<unsigned int>{}};

      row[j] = current;
    }

    triangle[i] = row;
  }

  for (size_t i = table.size(); i > 0; i--) {
    for (size_t j = table[i - 1].size(); j > 0; j--) {
      Node left_child;
      Node right_child;

      try {
        left_child = get_left_child(i - 1, j - 1);
        right_child = get_right_child(i - 1, j - 1);
      } catch (int) {
        triangle[i - 1][j - 1].greatest_path.push_back(triangle[i - 1][j - 1].val);
        continue;
      }

      if (left_child.greatest_sum > right_child.greatest_sum) {
        triangle[i - 1][j - 1].greatest_sum +=
            left_child.greatest_sum;

        triangle[i - 1][j - 1].greatest_path = left_child.greatest_path;
        triangle[i - 1][j - 1].greatest_path.push_front(triangle[i - 1][j - 1].val);
      } else {
        triangle[i - 1][j - 1].greatest_sum +=
	  right_child.greatest_sum;

        triangle[i - 1][j - 1].greatest_path = right_child.greatest_path;
        triangle[i - 1][j - 1].greatest_path.push_front(triangle[i - 1][j - 1].val);
      }
    }
  }
}


Triangle::~Triangle() {
  for (size_t i = 0; i < triangle_rows; i++)
    delete[] triangle[i];

  delete[] triangle;
}


const Node& Triangle::get() const {
  if (!triangle) throw "Triangle is empty!";

  return triangle[0][0];
}


Node Triangle::get_left_child(size_t i, size_t j) const {
  if (i == triangle_rows - 1)
    throw -1;

  return triangle[i + 1][j];
}

Node Triangle::get_right_child(size_t i, size_t j) const {
  if (i == triangle_rows - 1)
    throw -1;

  return triangle[i + 1][j + 1];
}
