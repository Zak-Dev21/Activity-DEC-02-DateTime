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

    void addSeconds(int s);
    void subtractSeconds(int s);
    void addMinutes(int m);
    void subtractMinutes(int m);
    void addHours(int h);
    void subtractHours(int h);
};

#endif
