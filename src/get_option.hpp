// get_option.hpp
#pragma once

#include <string>

struct Options {
    int year = 0;
    int month = 0;
    int day = 0;
    bool valid = true;
    bool help = false;
};

Options get_option(int argc, char* argv[]);
void print_help(const std::string& program_name);
