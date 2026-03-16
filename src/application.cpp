
#include <application.hpp>
// function to get file name form user:
std::string application::File::get_file_name()
{
    std::cout << "file name:";
    std::cin.ignore();
    std::getline(std::cin, file_name);
    return file_name;
}
// take the input  from user :
std::string application::controll()
{
    


    
}
bool application::File::read()
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
        return true;
    }
    else
    {
        std::cout << "Unable to open file.\n";
        return false;
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
bool application::File::write()
{
    std::fstream file(file_name, std::ios::app);
    std::cout << "current file:" << file_name << "\n";
    if (file.is_open())
    {
        
    }
    else
    {
        std::cout << "Unable to open file.\n";
        return false;
    }
}
void application::rendering(const  std::vector<std::string> & file_content)
{
    size_t size = file_content.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << file_content[i] << "\n";
    }
}
