#include <iostream>
using namespace std;

int main() {

    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int day = 0;
    int inputMonth;
    int inputDay;
    cin >> inputMonth;
    cin >> inputDay;

    int dayOfMonth = 1;
    int month = 1;
    for (int i = 1; i <= 12 * 31; ++i) {

        if (inputDay == dayOfMonth && inputMonth == month) {
            cout << week[day] << endl;
            break;
        }

        if (month == 2 && dayOfMonth == 28) {
            month++;
            dayOfMonth = 1;
        } else if ((month == 4 || month == 6 || month == 9 || month == 11) && dayOfMonth == 30) {
            month++;
            dayOfMonth = 1;
        } else if (dayOfMonth == 31) {
            month++;
            dayOfMonth = 1;
        } else
            dayOfMonth++;

        day = (day == 6 ? 0 : day + 1);
    }
    return 0;
}