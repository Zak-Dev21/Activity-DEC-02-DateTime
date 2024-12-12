#include "DateTime.h"
#include "Date.h"
#include "Time.h"

using namespace std;

int main() {
    DateTime dt1(2024, 12, 31, 23, 59, 59);
    dt1.display();

    DateTime dt2(2024, 1, 1, 0, 0, 0);
    dt2.display();

    // Test DateTime difference
    cout << "Calculating difference between two DateTime objects:\n";
    dt1.difference(dt2);

    // Test Date arithmetic boundaries
    Date date(2024, 12, 31);
    date.addDays(1);  // Test crossing year boundary
    cout << "After adding 1 day: " << date.getYear() << "-" << date.getMonth() << "-" << date.getDay() << "\n";

    date.subtractDays(1);  // Back to original date
    date.subtractDays(31); // Test crossing month boundary
    cout << "After subtracting 31 days: " << date.getYear() << "-" << date.getMonth() << "-" << date.getDay() << "\n";

    // Test Time arithmetic boundaries
    Time time(23, 59, 59);
    time.addSeconds(1);  // Test crossing day boundary
    cout << "After adding 1 second: " << time.getHours() << ":" << time.getMinutes() << ":" << time.getSeconds() << "\n";

    time.subtractSeconds(1);  // Back to original time
    time.addMinutes(1);       // Test crossing hour boundary
    cout << "After adding 1 minute: " << time.getHours() << ":" << time.getMinutes() << ":" << time.getSeconds() << "\n";

    // Test the format method
    cout << dt1.format("YYYY-MM-DD HH:MM:SS") << "\n";
    cout << dt1.format("Today is YYYY-MM-DD, and the time is HH:MM") << "\n";

    return 0;
}
