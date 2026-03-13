
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
std::string decision()
{
    std::string user_input_dec;
    do
    {
        std::cout << "Enter :q to quit or :r to read a file or :i to write into a file\n";
        std::cin >> user_input_dec;
    } while (user_input_dec != ":q" && user_input_dec != ":r" && user_input_dec != ":i");

    return user_input_dec;
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
            file << input << "\n";
        }
        file.close();
        return true;
    }
    else
    {
        std::cout << "Unable to open file.\n";
        return false;
    }
}
void print_content(std::vector<std::string> &content)
{
    size_t size = content.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << content[i] << "\n";
    }
}

int main(int argc, char *argv[])
{
    bool continues = true;
    std::string file_name;
    if (argc >= 2)
    {
        file_name = argv[1];
    }
    while (continues)
    {
        std::vector<std::string> file_content;
        if (!file_content.empty())
        {
            file_content = read_from_file(file_name);
            print_content(file_content);
            file_content.clear();
        }
        std::string user_dec = decision();
        if (user_dec == ":q")
        {
            continues = false;
        }
        else
        {

            file_name = get_input();
            if (user_dec == ":i")
            {
                write_to_file(file_name);
            }
        }
    }

    return 0;
}
