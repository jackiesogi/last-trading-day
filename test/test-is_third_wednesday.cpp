// test-is_third_wednesday.cpp
#include <iostream>
#include "../src/dayutils.hpp"
#include <cassert>

void test_is_third_wednesday() {
    std::cout << "Testing is_third_wednesday... ";
    assert(is_third_wednesday(2024, 10, 16) == true);
    assert(is_third_wednesday(2024, 10, 17) == false);
    std::cout << "Passed!" << std::endl;
}
