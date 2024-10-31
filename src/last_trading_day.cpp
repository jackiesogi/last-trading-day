#include <iostream>
#include "dayutils.hpp"
#include "get_option.hpp"

int main(int argc, char* argv[]) {
    Options options = get_option(argc, argv);
    
    if (options.help) {
        print_help(argv[0]);
        return 0;
    }
    
    int year, month, day;
    if (options.year == 0 && options.month == 0 && options.day == 0) {
        get_today_date(year, month, day);
    } else {
        year = options.year;
        month = options.month;
        day = options.day;
    }

    if (!is_valid_date(year, month, day)) {
        std::cerr << "Error: Invalid date." << std::endl;
        return 1;
    }

    if (is_third_wednesday(year, month, day)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}

