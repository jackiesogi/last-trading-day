// test-get_option.cpp
#include <iostream>
#include "../src/get_option.hpp"
#include <cassert>

void test_get_option() {
    const char* args[] = {"program", "-Y", "2024", "-M", "10", "-D", "18"};
    Options options = get_option(7, const_cast<char**>(args));

    assert(options.year == 2024);
    assert(options.month == 10);
    assert(options.day == 18);
    assert(options.valid);
}
