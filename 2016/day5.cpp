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
  while (num < 8) {
    string temp = input + to_string(prefix++);
    string hash = md5(temp);
    string subhash = hash.substr(0, 5);
    if (subhash == "00000") {
      num++;
      cout << hash << endl;
      pass += hash[5];
    }
  }
  cout << pass << endl;
  return 0;
}
