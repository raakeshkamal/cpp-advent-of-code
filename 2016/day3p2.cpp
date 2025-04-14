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
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < input_list.size(); i = i + 3) {

      if ((input_list[i][j] + input_list[i + 1][j] > input_list[i + 2][j]) &&
          (input_list[i + 1][j] + input_list[i + 2][j] > input_list[i][j]) &&
          (input_list[i + 2][j] + input_list[i][j] > input_list[i + 1][j])) {
        valid_num++;
      }
      for (const auto &side : input_list[i]) {
        // cout << side << ",";
      }
      // cout << endl;
    }
  }
  cout << "valid_num: " << valid_num << endl;
  return 0;
}
