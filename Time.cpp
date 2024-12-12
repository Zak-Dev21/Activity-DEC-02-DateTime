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

void Time::addSeconds(int s) {
    seconds += s;
    minutes += seconds / 60;
    seconds %= 60;
    addMinutes(0);  // Normalize
}

void Time::subtractSeconds(int s) {
    seconds -= s;
    while (seconds < 0) {
        seconds += 60;
        subtractMinutes(1);
    }
}

void Time::addMinutes(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
    addHours(0);  // Normalize
}

void Time::subtractMinutes(int m) {
    minutes -= m;
    while (minutes < 0) {
        minutes += 60;
        subtractHours(1);
    }
}

void Time::addHours(int h) {
    hours += h;
    hours %= 24;  // Normalize for 24-hour time
}

void Time::subtractHours(int h) {
    hours -= h;
    while (hours < 0) {
        hours += 24;
    }
}
