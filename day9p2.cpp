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

// string rec_unwrap(string input, int rep_in) {
//   smatch match;
//   cout << input << " " << rep_in << endl;
//   string total_rep = input;

//   if (regex_search(input, match, pattern)) {
//     string prefix = input.substr(0, match.position());
//     string postfix = input.substr(match.position() + match.length());
//     unsigned int len = stoi(match[1].str());
//     unsigned int rep = stoi(match[2].str());
//     string rep_str = postfix.substr(0, len);
//     string non_rep_str = postfix.substr(len);
//     total_rep = prefix + rec_unwrap(rep_str, rep) + rec_unwrap(non_rep_str,
//     1);
//   }
//   string out = "";
//   for (int i = 0; i < rep_in; i++) {
//     out += total_rep;
//   }
//   return out;
// }

bool unwrap(string &input) {
  regex pattern("\\(([0-9]+)x([0-9]+)\\)");
  smatch match;
  string prefix = "";
  string postfix = "";
  bool res = regex_search(input, match, pattern);

  if (res) {
    prefix = input.substr(0, match.position());
    postfix = input.substr(match.position() + match.length());
    unsigned int len = stoi(match[1].str());
    unsigned int rep = stoi(match[2].str());
    string rep_str = postfix.substr(0, len);
    string non_rep_str = postfix.substr(len);
    input = prefix;
    for (int i = 0; i < rep; i++) {
      input += rep_str;
    }
    input += non_rep_str;
  }
  return res;
}

void read_file(string filename, string &input, bool &err) {
  err = false;
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "File not found" << endl;
    err = true;
  }

  string line;
  input = "";
  while (getline(file, line)) {
    if (!line.empty()) {
      input += line;
    }
  }
  file.close();
}

void write_file(string filename, string input, bool &err) {
  std::ofstream file(filename);

  if (file.is_open()) {
    file << input;
    file.close();
  } else {
    cerr << "Unable to open file." << endl;
  }
}

int main() {

  string full_buf;
  bool err = false;

  // copy to unwrap.txt;
  // read_file("/home/tall-roland/Documents/cpp-advent-of-code/test.txt",
  // full_buf,
  //           err);
  // write_file("/home/tall-roland/Documents/cpp-advent-of-code/unwrap.txt",
  // full_buf, err);
  bool ret = true;

  do {
    read_file("/home/tall-roland/Documents/cpp-advent-of-code/unwrap.txt",
              full_buf, err);
    ret = unwrap(full_buf);
    write_file("/home/tall-roland/Documents/cpp-advent-of-code/unwrap.txt",
               full_buf, err);
    //break;
  } while (ret);

  return 0;
}
