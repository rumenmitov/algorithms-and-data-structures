#include <cstring>
#include <iostream>
#include <vector>

#include "Triangle.h"


using namespace std;

int main(int argc, char* argv[]) {

  char input_row[1024];
  cin.getline(input_row, sizeof(input_row));

  vector<vector<unsigned int>> table;

  while (strncmp(input_row, "", sizeof(input_row)) != 0) {
    vector<unsigned int> row;

    char* input = strtok(input_row, " ");
    while (input != nullptr) {
      row.push_back(atoi(input));
      input = strtok(nullptr, " ");
    }

    table.push_back(row);
    cin.getline(input_row, sizeof(input_row));
  }

  Triangle triangle(table);

  const Node solution = triangle.get();

  cout << solution.greatest_sum << endl;

  for (auto x : solution.greatest_path) cout << x << " ";

  cout << endl;
  
  return 0;
}
