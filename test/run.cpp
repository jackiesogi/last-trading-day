#include <iostream>

// Function declarations for the tests
void test_get_option();
void test_get_today_date();
void test_is_third_wednesday();
void test_is_valid_date();

int main() {
    std::cout << "Running tests..." << std::endl;

    test_get_option();
    test_get_today_date();
    test_is_third_wednesday();
    test_is_valid_date();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}

