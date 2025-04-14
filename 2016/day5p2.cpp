#include <cstdint>
#include <iomanip>
#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string md5(const string &str) {
  unsigned char hash[MD5_DIGEST_LENGTH];

  MD5_CTX md5;
  MD5_Init(&md5);
  MD5_Update(&md5, str.c_str(), str.size());
  MD5_Final(hash, &md5);

  stringstream ss;

  for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
    ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
  }
  return ss.str();
}

int main() {
  string input = "uqwqemis";
  unsigned long prefix = 0;
  unsigned int num = 0;
  string pass = "";
  vector<uint8_t> vec(8, UINT8_MAX);
  while (num < 8) {
    string temp = input + to_string(prefix++);
    string hash = md5(temp);
    if (hash.substr(0, 5) == "00000") {
      uint8_t pos = (uint8_t)hash[5] - (uint8_t)'0';
      cout << hash << " " << (int)pos << endl;
      if ((pos < 8) && (vec[pos] == UINT8_MAX)) { 
        cout << hash << endl;
        vec[pos] = (uint8_t)hash[6];
        num++;
      }
      // break;
    }
  }
  for (const auto &num : vec) {
    pass += (char)num;
  }
  cout << pass << endl;
  return 0;
}
