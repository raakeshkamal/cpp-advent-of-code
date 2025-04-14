#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void get_most_common(vector<string> &input) {
  size_t len = input[0].length();
  string res = "";
  for (int i = 0; i < len; i++) {
    unordered_map<char, unsigned int> hash_map;
    for (int j = 0; j < input.size(); j++) {
      if (hash_map.find(input[j][i]) == hash_map.end()) {
        hash_map[input[j][i]] = 1;
      } else {
        hash_map[input[j][i]]++;
      }
    }
    unsigned int max = 0;
    char out = UINT8_MAX;
    for (auto &pair : hash_map) {
      if (pair.second > max) {
        max = pair.second;
        out = pair.first;
      }
    }
    res += out;
  }
  cout << res << endl;
}

void get_least_common(vector<string> &input) {
  size_t len = input[0].length();
  string res = "";
  for (int i = 0; i < len; i++) {
    unordered_map<char, unsigned int> hash_map;
    for (int j = 0; j < input.size(); j++) {
      if (hash_map.find(input[j][i]) == hash_map.end()) {
        hash_map[input[j][i]] = 1;
      } else {
        hash_map[input[j][i]]++;
      }
    }
    unsigned int max = UINT32_MAX;
    char out = UINT8_MAX;
    for (auto &pair : hash_map) {
      if (pair.second < max) {
        max = pair.second;
        out = pair.first;
      }
    }
    res += out;
  }
  cout << res << endl;
}

int main() {
  ifstream file("/home/tall-roland/Documents/cpp-advent-of-code/input6.txt");
  if (!file.is_open()) {
    cerr << "File not found" << endl;
    return 1;
  }
  vector<string> input_list;
  string line;
  while (getline(file, line)) {
    if (!line.empty()) {
      input_list.push_back(line);
    }
    // cout << endl;
  }
  file.close();
  get_least_common(input_list);
  return 0;
}
