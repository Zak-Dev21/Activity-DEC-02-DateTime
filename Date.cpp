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
