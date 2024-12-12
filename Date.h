#ifndef DATE_H
#define DATE_H

class Date {
private:
    int year;
    int month;
    int day;

    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;

public:
    Date(int y, int m, int d);
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void addDays(int d);
    void subtractDays(int d);
    void addMonths(int m);
    void subtractMonths(int m);
    void addYears(int y);
    void subtractYears(int y);
};

#endif
