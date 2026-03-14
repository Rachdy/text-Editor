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
        std::string file_name;
        std::vector<std::string> file_content;
        std::fstream file;
        bool write();
        bool read();
        File()
        {
            std::fstream file(file_name, std::ios::in);
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

    std::string decision();
    void rendering();

}

#endif