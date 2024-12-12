#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

class DateTime : public Date, public Time {
public:
    DateTime(int y, int m, int d, int h, int min, int s);
    void display() const;
    void difference(const DateTime& other) const;
    string format(const string& formatString) const; // New method
};

#endif
