#pragma once
#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>

namespace application
{
    class File
    {
    private:
        std::string file_name;
        std::vector<std::string> file_content;

    public:
        std::fstream file;
        bool write();
        bool read();
        bool create_new_file();
        std::string get_file_name();

        File()
        {
            file_name = "";
        }
        ~File()
        {
            file.close();
        }
    };

    struct Cursor
    {
        uint32_t cursor_x;
        uint32_t cursor_y;
    };

    enum class Controller_MODE
    {
        input_MODE,   // after pressing i->input_MODE(for getting new content of files)
        command_MODE, // after pressing esp->command_Mode(for controlling the text editor)
    };
    std::string controll();
    void rendering(const std::vector<std::string> &file_content);

}

#endif