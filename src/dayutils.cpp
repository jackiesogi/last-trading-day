// dayutils.cpp
#include "dayutils.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

int get_weekday(int year, int month, int day) {
    if (month == 1 || month == 2) {
        month += 12;
        --year;
    }
    int K = year % 100;
    int J = year / 100;
    int weekday_index = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;
    weekday_index = (weekday_index + 5) % 7 + 1;
    return weekday_index;
}

void get_today_date(int &year, int &month, int &day) {
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
}

bool is_valid_date(int year, int month, int day) {

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Check for February (month 2)
    if (month == 2) {
        // Check if it's a leap year
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28)) return false;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    }

    return true;
}

bool is_third_wednesday(int year, int month, int day) {
    int weekday = get_weekday(year, month, day);
    if (weekday != 3) {
        return false;
    }

    int count = 0;
    for (int d = 1; d <= 31; ++d) {
        if (!is_valid_date(year, month, d)) {
            break;
        }
        if (get_weekday(year, month, d) == 3) {
            count++;
        }
        if (count == 3) {
            return (d == day);
        }
    }
    return false;
}
