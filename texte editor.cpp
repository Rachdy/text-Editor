
#include <iostream>
#include<string>
#include<fstream>

int main()
{
    std::string file_name;
    std::cout << "enter File name:";
    std::cin >> file_name;
    std::fstream file(file_name, std::ios::in);
    if (file.is_open()) {
        std::string s;
        while (getline(file, s)) {
            std::cout << s << "\n";

        }
        file.close();
    }
    else {
        std::cout << "Unable to open file.\n";
    }

    return 0;

}
