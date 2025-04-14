#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
    std::ifstream file("/home/tall-roland/Documents/cpp-advent-of-code/input2.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::vector<std::string> inputs;
    std::string input;
    while (std::getline(file, input, '\n'))
    {
        inputs.push_back(input);
    }

    unsigned int i = 5;
    for (const auto &str : inputs)
    {
        // std::cout << str << std::endl;
        for (char c : str)
        {
            // std::cout << c << " -> ";
            int diff;
            switch (c)
            {
            case 'U':
                diff = -3;
                if ((i + diff) >= 1 && (i + diff) <= 9)
                    i += diff;
                break;
            case 'D':
                diff = 3;
                if ((i + diff) >= 1 && (i + diff) <= 9)
                    i += diff;
                break;
            case 'L':
                diff = -1;
                if(i % 3 != 1)
                    i += diff;
                break;
            case 'R':
                diff = 1;
                if(i % 3 != 0)
                    i += diff;
                break;
            }
            // std::cout << i << std::endl;
        }
        // std::cout << std::endl;
        // break;
        std::cout << i << ' ';
    }

    file.close();
}