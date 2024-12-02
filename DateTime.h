#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"
#include "Time.h"
#include <iostream>

class DateTime : public Date, public Time {
public:
    DateTime(int y, int m, int d, int h, int min, int s);
    void display() const;
};

#endif
