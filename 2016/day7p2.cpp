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

void get_aba(vector<string> input_vec, vector<string> &output_vec) {
  for (const auto &input : input_vec) {
    for (int i = 0; i < input.length() - 3 + 1; i++) {
      if ((input[i] == input[i + 2]) && (input[i] != input[i + 1])) {
        output_vec.push_back(input.substr(i, 3));
      }
    }
  }
}

int main() {
  ifstream file("/home/tall-roland/Documents/cpp-advent-of-code/input7.txt");
  if (!file.is_open()) {
    cerr << "File not found" << endl;
    return 1;
  }
  regex delimiter("\\[|\\]");
  vector<string> input_list;
  string line;
  int res = 0;
  while (getline(file, line)) {
    if (!line.empty()) {
      // cout << line << endl;
      input_list.push_back(line);
      vector<string> out_list;
      vector<string> in_list;
      sregex_token_iterator iter(line.begin(), line.end(), delimiter, -1);
      sregex_token_iterator end;
      int i = 0;
      for (; iter != end; iter++) {
        // cout << *iter;
        if ((i++ % 2) == 0) {
          // cout << "!";
          out_list.push_back(*iter);
        } else {
          // cout << "?";
          in_list.push_back(*iter);
        }
      }
      bool ssl = false;
      vector<string> aba_list;
      vector<string> bab_list;
      unordered_map<string, int> hash_map;
      get_aba(out_list, aba_list);
      for (auto &aba : aba_list) {
        // reverse(aba.begin(), aba.end());
        string temp = "";
        temp = temp + aba[1] + aba[0] + aba[1];
        hash_map[temp] = 1;
      }
      get_aba(in_list, bab_list);
      for (const auto &bab : bab_list) {
        if (hash_map.find(bab) != hash_map.end()) {
          ssl = true;
        }
      }
      if (ssl) {
        res++;
        cout << line << endl;
      }
    }
  }
  cout << res << endl;
  file.close();
  return 0;
}
