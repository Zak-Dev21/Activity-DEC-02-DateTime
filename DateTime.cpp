#include "DateTime.h"

DateTime::DateTime(int y, int m, int d, int h, int min, int s)
    : Date(y, m, d), Time(h, min, s) {}

void DateTime::display() const {
    std::cout << getYear() << "-" << getMonth() << "-" << getDay() << " "
        << getHours() << ":" << getMinutes() << ":" << getSeconds() << "\n";
}
