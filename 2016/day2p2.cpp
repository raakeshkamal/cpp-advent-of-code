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

    char keypad[5][5] = {
        {' ', ' ', '1', ' ', ' '},
        {' ', '2', '3', '4', ' '},
        {'5', '6', '7', '8', '9'},
        {' ', 'A', 'B', 'C', ' '},
        {' ', ' ', 'D', ' ', ' '}};

    std::vector<std::string> inputs;
    std::string input;
    while (std::getline(file, input, '\n'))
    {
        inputs.push_back(input);
    }

    unsigned int i = 2;
    unsigned int j = 0;
    for (const auto &str : inputs)
    {
        // std::cout << str << std::endl;
        for (char c : str)
        {
            // std::cout << c << " -> ";
            int iDiff = 0;
            int jDiff = 0;
            switch (c)
            {
            case 'U':
                iDiff = -1;
                break;
            case 'D':
                iDiff = 1;
                break;
            case 'L':
                jDiff = -1;
                break;
            case 'R':
                jDiff = 1;
                break;
            }
            if ((i + iDiff) >= 0 && (i + iDiff) < 5)
            {
                if ((j + jDiff) >= 0 && (j + jDiff) < 5)
                {
                    if (keypad[i + iDiff][j + jDiff] != ' ')
                    {
                        i = i + iDiff;
                        j = j + jDiff;
                    }
                }
            }
            // std::cout << i << std::endl;
        }
        // std::cout << std::endl;
        // break;
        std::cout << keypad[i][j] << ' ';
    }

    file.close();
}