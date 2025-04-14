#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

struct Location {
  int x;
  int y;
};

std::unordered_map<std::string, int> LocationMap;

bool get_new_location(Location *new_loc, int vector, int distance) {
  for (int i = 1; i <= distance; i++) {
    switch (vector) {
    case 1:
      new_loc->x += 1;
      break;
    case 2:
      new_loc->y -= 1;
      break;
    case 3:
      new_loc->x -= 1;
      break;
    case 0:
      new_loc->y += 1;
      break;
    }
    std::string loc_str =
        std::to_string(new_loc->x) + "," + std::to_string(new_loc->y);
    if (LocationMap.find(loc_str) == LocationMap.end())
      LocationMap.insert({loc_str, 1});
    else {
      return true;
    }
  }
  return false;
}

int main() {
  std::ifstream file(
      "/home/tall-roland/Documents/cpp-advent-of-code/input1.txt");
  if (!file.is_open()) {
    std::cerr << "Failed to open the file." << std::endl;
    return 1;
  }

  std::vector<std::string> directions;
  std::string direction;
  while (std::getline(file, direction, ',')) {
    if (!direction.empty() && direction[0] == ' ') {
      direction.erase(0, 1);
    }
    directions.push_back(direction);
  }

  file.close();

  int ctr = 0;
  Location new_loc = {0, 0};
  int vector = 0; // 0: North, 1: East, 2: South, 3: West
  // Output the directions to verify
  for (const auto &dir : directions) {
    std::cout << dir << std::endl;
    switch (dir[0]) {
    case 'R':
      vector = (vector + 1) % 4;
      break;
    case 'L':
      vector = (vector + 3) % 4;
      break;
    }
    int distance = std::stoi(dir.substr(1));
    if (get_new_location(&new_loc, vector, distance)) {
      std::cout << "First location visited twice: (" << new_loc.x << ", "
                << new_loc.y << ")" << std::endl;
      break;
    }
  }

  std::cout << "Final position: (" << new_loc.x << ", " << new_loc.y << ")"
            << std::endl;

  return 0;
}
