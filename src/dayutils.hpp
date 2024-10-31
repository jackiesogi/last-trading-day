// dayutils.hpp
#pragma once

int get_weekday(int year, int month, int day);
void get_today_date(int &year, int &month, int &day);
bool is_valid_date(int year, int month, int day);
bool is_third_wednesday(int year, int month, int day);
