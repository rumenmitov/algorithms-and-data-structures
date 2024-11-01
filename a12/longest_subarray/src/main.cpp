#include <cstring>
#include <iostream>
#include <vector>

#include "LongestSubarray.h"

using namespace std;


int main(int argc, char* argv[]) {
    
    char input[1024];
    cin.getline(input, sizeof(input));
    
    std::vector<int> input_arr;

    char* digit = strtok(input, " ");
    
    while (digit != nullptr) {
      input_arr.push_back(atoi(digit));
      digit = strtok(nullptr, " ");
    }

    LongestSubarray solution(input_arr);

    for (int x : solution.get()) {
      cout << x << " ";
    }

    cout << endl;
    
    return 0;
}
