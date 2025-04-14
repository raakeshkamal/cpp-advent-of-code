#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct triangle {
  unsigned int a;
  unsigned int b;
  unsigned int c;
};

int main() {
  ifstream file("/home/tall-roland/Documents/cpp-advent-of-code/input3.txt");
  if (!file.is_open()) {
    cerr << "File not found" << endl;
    return 1;
  }
  vector<vector<unsigned int>> input_list;
  string line;
  while (getline(file, line)) {
    stringstream s(line);
    string side;
    vector<unsigned int> triangle;
    while (getline(s, side, ' ')) {
      if (!side.empty()) {
        // cout << side << ",";
        triangle.push_back(stoi(side));
      }
    }
    // cout << endl;
    input_list.push_back(triangle);
  }
  file.close();
  unsigned int valid_num = 0;
  for (const auto &triangle : input_list) {
    if (triangle.size() != 3) {
      cout << "Invalid Input";
      return 1;
    }
    if ((triangle[0] + triangle[1] > triangle[2]) &&
        (triangle[1] + triangle[2] > triangle[0]) &&
        (triangle[2] + triangle[0] > triangle[1])) {
      valid_num++;
    }
    for (const auto &side : triangle) {
      // cout << side << ",";
    }
    // cout << endl;
  }
  cout << "valid_num: " << valid_num << endl;
  return 0;
}
