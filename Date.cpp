#include "Date.h"

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) const {
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m - 1];
}

void Date::addDays(int d) {
    while (d > 0) {
        int daysLeftInMonth = daysInMonth(month, year) - day;
        if (d <= daysLeftInMonth) {
            day += d;
            return;
        }
        d -= (daysLeftInMonth + 1);
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::subtractDays(int d) {
    while (d > 0) {
        if (d < day) {
            day -= d;
            return;
        }
        d -= day;
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
}

void Date::addMonths(int m) {
    month += m;
    while (month > 12) {
        month -= 12;
        year++;
    }
    if (day > daysInMonth(month, year)) {
        day = daysInMonth(month, year);
    }
}

void Date::subtractMonths(int m) {
    month -= m;
    while (month < 1) {
        month += 12;
        year--;
    }
    if (day > daysInMonth(month, year)) {
        day = daysInMonth(month, year);
    }
}

void Date::addYears(int y) {
    year += y;
    if (month == 2 && day == 29 && !isLeapYear(year)) {
        day = 28;
    }
}

void Date::subtractYears(int y) {
    year -= y;
    if (month == 2 && day == 29 && !isLeapYear(year)) {
        day = 28;
    }
}
