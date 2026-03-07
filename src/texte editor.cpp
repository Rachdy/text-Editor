
#include <iostream>
#include<string>
#include<fstream>

int main(int argc, char* argv[])
{

    if (argc >= 2) {
        bool continues = true;
        while (true) {
            std::fstream file(argv[1], std::ios::in);
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

            std::string user_input;
            do {
                std::cout << "Enter :quit to quit or :continue to read other file:";
                std::cin >> user_input;
            } while (user_input != ":quit" || user_input != ":continue");
            if (user_input == ":quit") {
                break;
            }
            else continue;
        }
    }

    else {
        std::cout << "missing file name\n";
    }

    return 0;

}
