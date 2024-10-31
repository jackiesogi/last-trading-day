// test-is_valid_date.cpp
#include <iostream>
#include "../src/dayutils.hpp"
#include <cassert>

void test_is_valid_date() {
    std::cout << "Testing is_valid_date... ";
    assert(is_valid_date(2024, 10, 18) == true);
    assert(is_valid_date(2024, 13, 1) == false); // Invalid month
    assert(is_valid_date(2024, 2, 29) == true);  // Valid leap year date
    assert(is_valid_date(2023, 2, 29) == false); // Invalid non-leap year date
    std::cout << "Passed!" << std::endl;
}
