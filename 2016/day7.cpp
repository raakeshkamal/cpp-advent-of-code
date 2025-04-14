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

bool check_abba(string input) {
  for (int i = 0; i < input.length() - 4 + 1; i++) {
    if ((input[i] == input[i + 3]) && (input[i + 1] == input[i + 2]) &&
        (input[i] != input[i + 1])) {
      return true;
    }
  }
  return false;
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
      bool tls = false;
      for (const auto &word : out_list) {
        tls = tls || check_abba(word);
      }
      for (const auto &word : in_list) {
        tls = tls && !check_abba(word);
      }
      if (tls) {
        // cout << "-y";
        // cout << line << endl;
        res++;
      } else {
        // cout << "-n";
      }
      // cout << endl;

      // break;
    }
    // cout << endl;
  }
  cout << res << endl;
  file.close();
  return 0;
}
