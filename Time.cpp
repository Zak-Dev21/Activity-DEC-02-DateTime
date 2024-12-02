#include "Time.h"

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getSeconds() const {
    return seconds;
}
