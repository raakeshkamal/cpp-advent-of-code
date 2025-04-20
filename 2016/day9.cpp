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

void unwrap(string input, unsigned int &pos, string &final_prefix,
            string &final_postfix) {
  regex pattern("\\(([0-9]+)x([0-9]+)\\)");
  smatch match;
  final_prefix = "";
  final_postfix = "";

  if (regex_search(input, match, pattern)) {
    string prefix = input.substr(0, match.position());
    string postfix = input.substr(match.position() + match.length());
    final_prefix = prefix;
    unsigned int len = stoi(match[1].str());
    unsigned int rep = stoi(match[2].str());
    string rep_str = postfix.substr(0, len);
    string non_rep_str = postfix.substr(len);
    pos = match.position() + match.length() + len;
    final_postfix = non_rep_str;
    for (int i = 0; i < rep; i++) {
      final_prefix += rep_str;
    }
  }
  // cout << input << " " << pos << " " << final_prefix << " " << final_postfix
  //      << endl;
}

int main() {
  ifstream file("/home/tall-roland/Documents/cpp-advent-of-code/input9.txt");
  if (!file.is_open()) {
    cerr << "File not found" << endl;
    return 1;
  }

  string line;
  string full_buf = "";
  while (getline(file, line)) {
    if (!line.empty()) {
      full_buf += line;
    }
  }
  file.close();
  unsigned int idx = 0;
  unsigned int pos;
  unsigned int res = 0;
  while (idx < full_buf.length()) {
    string input = full_buf.substr(idx);
    // cout << "In: " << input << endl;
    string final_prefix, final_postfix;
    unwrap(input, pos, final_prefix, final_postfix);
    cout << final_prefix; // << endl;
    res += final_prefix.length();
    idx += pos;
    // cout << "pos: " << idx << endl;
    // break;
  }
  cout << endl << res << endl;
  return 0;
}
