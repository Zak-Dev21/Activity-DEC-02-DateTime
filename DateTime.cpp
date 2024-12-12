#include "DateTime.h"
#include <cmath> // For std::abs
#include <sstream> // For string formatting

using namespace std;

DateTime::DateTime(int y, int m, int d, int h, int min, int s)
    : Date(y, m, d), Time(h, min, s) {}

void DateTime::display() const {
    cout << getYear() << "-" << getMonth() << "-" << getDay() << " "
        << getHours() << ":" << getMinutes() << ":" << getSeconds() << "\n";
}

void DateTime::difference(const DateTime& other) const {
    // Calculate total seconds for this DateTime
    int thisTotalSeconds = getYear() * 365 * 24 * 3600 + getMonth() * 30 * 24 * 3600 +
        getDay() * 24 * 3600 + getHours() * 3600 + getMinutes() * 60 + getSeconds();

    // Calculate total seconds for the other DateTime
    int otherTotalSeconds = other.getYear() * 365 * 24 * 3600 + other.getMonth() * 30 * 24 * 3600 +
        other.getDay() * 24 * 3600 + other.getHours() * 3600 + other.getMinutes() * 60 + other.getSeconds();

    // Absolute difference in seconds
    int totalDiff = std::abs(thisTotalSeconds - otherTotalSeconds);

    // Convert to days, hours, minutes, and seconds
    int days = totalDiff / (24 * 3600);
    totalDiff %= (24 * 3600);
    int hours = totalDiff / 3600;
    totalDiff %= 3600;
    int minutes = totalDiff / 60;
    int seconds = totalDiff % 60;

    // Display the result
    cout << "Difference: " << days << " days, " << hours << " hours, "
        << minutes << " minutes, " << seconds << " seconds.\n";
}

string DateTime::format(const std::string& formatString) const {
    ostringstream result;

    for (size_t i = 0; i < formatString.size(); ++i) {
        if (formatString[i] == 'Y' && formatString.substr(i, 4) == "YYYY") {
            result << getYear();
            i += 3; // Skip next 3 characters of "YYYY"
        }
        else if (formatString[i] == 'M' && formatString.substr(i, 2) == "MM") {
            result << (getMonth() < 10 ? "0" : "") << getMonth();
            i += 1; // Skip next character of "MM"
        }
        else if (formatString[i] == 'D' && formatString.substr(i, 2) == "DD") {
            result << (getDay() < 10 ? "0" : "") << getDay();
            i += 1; // Skip next character of "DD"
        }
        else if (formatString[i] == 'H' && formatString.substr(i, 2) == "HH") {
            result << (getHours() < 10 ? "0" : "") << getHours();
            i += 1; // Skip next character of "HH"
        }
        else if (formatString[i] == 'M' && formatString.substr(i, 2) == "MM" && i > 0) {
            result << (getMinutes() < 10 ? "0" : "") << getMinutes();
            i += 1; // Skip next character of "MM"
        }
        else if (formatString[i] == 'S' && formatString.substr(i, 2) == "SS") {
            result << (getSeconds() < 10 ? "0" : "") << getSeconds();
            i += 1; // Skip next character of "SS"
        }
        else {
            result << formatString[i];
        }
    }

    return result.str();
}
