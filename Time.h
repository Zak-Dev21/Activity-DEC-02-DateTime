#ifndef TIME_H
#define TIME_H

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s);
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
};

#endif
