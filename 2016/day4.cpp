#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct room {
  vector<string> words;
  unsigned int id;
  string checksum;
};

bool is_a_real_room(room &room) {
  vector<char> chars;
  vector<unsigned int> nums;
  unordered_map<char, unsigned int> hash_map;
  for (int j = 0; j < room.words.size(); j++) {
    string word = room.words[j];
    for (int i = 0; i < word.size(); i++) {
      if (hash_map.find(word[i]) == hash_map.end()) {
        hash_map[word[i]] = 1;
      } else {
        hash_map[word[i]]++;
      }
    }
  }
  for (const auto &pair : hash_map) {
    chars.push_back(pair.first);
    nums.push_back(pair.second);
  }
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = 0; j < nums.size() - i - 1; j++) {
      if (nums[j + 1] > nums[j]) {
        swap(chars[j + 1], chars[j]);
        swap(nums[j + 1], nums[j]);
      } else if (nums[j + 1] == nums[j] && chars[j + 1] < chars[j]) {
        swap(chars[j + 1], chars[j]);
        swap(nums[j + 1], nums[j]);
      }
    }
  }
  vector<char> subchars(chars.begin(), chars.begin() + 5);
  vector<unsigned int> subnums(nums.begin(), nums.begin() + 5);
  string new_checksum = "";
  for (int i = 0; i < 5; i++) {
    // cout << subchars[i] << ":" << subnums[i] << endl;
    new_checksum += subchars[i];
  }
  return (new_checksum == room.checksum);
}

void decrypt_words(room &room) {
  unsigned int diff = room.id % 26;
  for (auto &word : room.words) {
    string temp = "";
    for (char c : word) {
      uint8_t num = (uint8_t)c - 97;
      num = (num + diff) % 26;
      temp += (char)(num+97);
    }
    cout << temp << " " ;
  }
    cout << endl;
}

int main() {
  ifstream file("/home/tall-roland/Documents/cpp-advent-of-code/input4.txt");
  if (!file.is_open()) {
    cerr << "File not found" << endl;
    return 1;
  }
  vector<room> input_list;
  string line;
  while (getline(file, line)) {
    stringstream s(line);
    string temp;
    room new_room;
    while (getline(s, temp, '-')) {
      if (!temp.empty()) {
        int pos = temp.find("[");
        if (pos == string::npos) {
          // cout << temp << " ";
          new_room.words.push_back(temp);
        } else {
          string checksum = temp.substr(pos + 1, temp.size() - pos - 2);
          string id = temp.substr(0, pos);
          // cout << id << " " << checksum;
          new_room.id = stoi(id);
          new_room.checksum = checksum;
        }
      }
    }
    input_list.push_back(new_room);
    // cout << endl;
  }
  file.close();
  unsigned long id_sum = 0;
  for (auto &room : input_list) {
    for (auto &word : room.words) {
      // cout << word << " ";
    }
    // cout << room.id << " " << room.checksum << endl;
    if (is_a_real_room(room)) {
      id_sum += room.id;
      cout << room.id << endl;
      decrypt_words(room);
    }
    // break;
  }
  cout << id_sum << endl;
  return 0;
}
