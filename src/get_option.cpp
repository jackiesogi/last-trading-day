// get_option.cpp
#include "get_option.hpp"
#include <iostream>
#include <string>

Options get_option(int argc, char* argv[]) {
    Options options;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'Y':
                    if (i + 1 < argc) {
                        options.year = std::stoi(argv[++i]);
                    } else {
                        options.valid = false;
                    }
                    break;
                case 'M':
                    if (i + 1 < argc) {
                        options.month = std::stoi(argv[++i]);
                    } else {
                        options.valid = false;
                    }
                    break;
                case 'D':
                    if (i + 1 < argc) {
                        options.day = std::stoi(argv[++i]);
                    } else {
                        options.valid = false;
                    }
                    break;
                case 'h':
                    options.help = true;
                    break;
                case 'F':
                    // 可以添加相應處理
                    break;
                default:
                    options.valid = false;
                    break;
            }
        }
    }

    return options;
}

void print_help(const std::string& program_name) {
    std::cout << "Usage: " << program_name << " [OPTIONS]\n"
              << "Check if a given date is the third Wednesday of the month.\n\n"
              << "Options:\n"
              << "  -Y YEAR       Specify the year (e.g., -Y 2024)\n"
              << "  -M MONTH      Specify the month (1-12, e.g., -M 10)\n"
              << "  -D DAY        Specify the day (1-31, e.g., -D 16)\n"
              << "  -h            Display this help message\n"
              << "  -F            Accept a date string in the format \"$(date)\"\n\n"
              << "Examples:\n"
              << "  " << program_name << " -Y 2024 -M 10 -D 16  --> Order is not important.\n"
              << "  " << program_name << "  --> It will take today's date as an input.\n"
              << "  " << program_name << " -F \"$(date)\"  --> If your system has 'date' command\n";
}

