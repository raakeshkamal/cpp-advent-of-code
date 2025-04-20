#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
unsigned int rows = 6;
unsigned int cols = 50;
// /rect\s\dx\d/gm
// /rotate\srow\sy=\d\sby\s\d/gm
// /rotate\scolumn\sx=\d\sby\s\d/gm
void rect(string input, vector<vector<unsigned int>> &display) {
  regex pattern("rect\\s(\\d+)x(\\d+)");
  smatch match;

  if (regex_search(input, match, pattern)) {
    unsigned int row = stoi(match[2].str());
    unsigned int col = stoi(match[1].str());
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        display[i][j] = 1;
      }
    }
  }
}

void rotate(string input, vector<vector<unsigned int>> &display) {
  regex pattern_row("rotate\\srow\\sy=(\\d+)\\sby\\s(\\d+)");
  regex pattern_col("rotate\\scolumn\\sx=(\\d+)\\sby\\s(\\d+)");
  smatch match;

  if (regex_search(input, match, pattern_row)) {
    unsigned int row_idx = stoi(match[1].str());
    unsigned int len = stoi(match[2].str());
    vector<unsigned int> vec_row;
    for (int i = 0; i < cols; i++) {
      vec_row.push_back(display[row_idx][i]);
    }
    for (int i = 0; i < cols; i++) {
      display[row_idx][(i + len) % cols] = vec_row[i];
    }
  }
  if (regex_search(input, match, pattern_col)) {
    unsigned int col_idx = stoi(match[1].str());
    unsigned int len = stoi(match[2].str());
    vector<unsigned int> vec_col;
    for (int i = 0; i < rows; i++) {
      vec_col.push_back(display[i][col_idx]);
    }
    for (int i = 0; i < rows; i++) {
      display[(i + len) % rows][col_idx] = vec_col[i];
    }
  }
}

int main() {
  ifstream file("/home/tall-roland/Documents/cpp-advent-of-code/input8.txt");
  if (!file.is_open()) {
    cerr << "File not found" << endl;
    return 1;
  }
  vector<string> input_list;

  vector<vector<unsigned int>> display(rows, vector<unsigned int>(cols, 0));
  string line;
  int res = 0;
  while (getline(file, line)) {
    if (!line.empty()) {
      cout << line << endl;
      input_list.push_back(line);
      rect(line, display);
      rotate(line, display);
      // for (int i = 0; i < rows; i++) {
      //   for (int j = 0; j < cols; j++) {
      //     cout << display[i][j] << " ";
      //   }
      //   cout << endl;
      // }
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {

      if (display[i][j]) {
        res++;
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << endl;
  }
  cout << res << endl;
  file.close();
  return 0;
}
