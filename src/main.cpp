
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::string get_input()
{
    std::string file_name;
    std::cout << "file name:";
    std::cin >> file_name;
    return file_name;
}
std::vector<std::string> read_from_file(std::string file_name)
{
    std::fstream file(file_name, std::ios::in);
    std::vector<std::string> lines;
    if (file.is_open())
    {
        std::string s;
        while (getline(file, s))
        {
            lines.push_back(s);
        }
        file.close();
        return lines;
    }
    else
    {
        std::cout << "Unable to open file.\n";
        return lines;
    }
}
void print_content(std::vector<std::string> content)
{
    size_t size = content.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << content[i] << "\n";
    }
}

int main(int argc, char *argv[])
{

    if (argc >= 2)
    {
        bool continues = true;
        std::string file_name = argv[1];
        while (continues)
        {

            std::vector<std::string> file_content = read_from_file(file_name);
            if (file_content.empty())
            {
                std::cout << "file is empty";
            }
            else
                print_content(file_content);

            std::string user_input;
            do
            {
                std::cout << "Enter :quit to quit or :continue to read other file:";
                std::cin >> user_input;
            } while (user_input != ":quit" && user_input != ":continue");
            if (user_input == ":quit")
            {
                continues = false;
            }
            else
            {
                file_name = get_input();
            }
        }
    }

    else
    {
        std::cout << "missing file name\n";
    }

    return 0;
}
