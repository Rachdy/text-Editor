
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// function to get file name form user : return file name : string
std::string get_input()
{
    std::string file_name;
    std::cout << "file name:";
    std::cin.ignore();
    std::getline(std::cin, file_name);
    return file_name;
}
// take the decision string from user : and return booling variable
bool decision()
{
    std::string user_input_dec;
    do
    {
        std::cout << "Enter :q to quit or :c to read other file\n";
        std::cin >> user_input_dec;
    } while (user_input_dec != ":q" && user_input_dec != ":c");

    if (user_input_dec == ":q")
    {
        return false;
    }
    else
    {
        return true;
    }
}

std::vector<std::string> read_from_file(std::string file_name)
{
    std::fstream file(file_name, std::ios::in);
    std::cout << "current file:" << file_name << "\n";
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
std::vector<std::string> read_content()
{
    std::vector<std::string> new_content;
    std::string input;
    std::cout << "Enter :s to save and close the file:\n";
    while (std::getline(std::cin, input) && input != ":s")
    {
        new_content.push_back(input);
    }
    return new_content;
}
bool write_to_file(std::string file_name)
{
    std::fstream file(file_name, std::ios::app);
    std::cout << "current file:" << file_name << "\n";
    if (file.is_open())
    {
        std::string input;
        std::cout << "write your new content: and type :s to save and close the file:\n";

        while (std::getline(std::cin, input) && input != ":s")
        {
            return true;
        }
    }
    else
    {
        std::cout << "Unable to open file.\n";
        return false;
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
                std::cout << "file is empty\n";
            }
            else
            {
                print_content(file_content);
            }

            if (!decision())
            {
                continues = false;
            }
            else

                file_name = get_input();
        }
    }

    else
    {
        std::cout << "missing file name\n";
    }

    return 0;
}
