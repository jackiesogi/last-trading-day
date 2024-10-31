// test-get_today_date.cpp
#include <iostream>
#include "../src/dayutils.hpp"
#include <cassert>

void test_get_today_date() {
    int year, month, day;
    get_today_date(year, month, day);
    std::cout << "Testing get_today_date... ";
    assert(year > 2000);
    assert(month >= 1 && month <= 12);
    assert(day >= 1 && day <= 31);
    std::cout << "Passed!" << std::endl;
}
