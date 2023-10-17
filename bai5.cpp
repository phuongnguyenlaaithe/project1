#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // Check if the string has the correct format (YYYY-MM-DD)
    if (s.length() != 10 || s[4] != '-' || s[7] != '-')
    {
        cout << "INCORRECT" << endl;
        return 0;
    }

    string year_str = s.substr(0, 4);
    string month_str = s.substr(5, 2);
    string date_str = s.substr(8, 2);

    int year, month, date;

    year = stoi(year_str);
    month = stoi(month_str);
    date = stoi(date_str);

    if (month < 1 || month > 12 || date < 1 || date > 31)
    {
        cout << "INCORRECT" << endl;
        return 0;
    }

    cout << year << " " << month << " " << date << endl;

    return 0;
}
