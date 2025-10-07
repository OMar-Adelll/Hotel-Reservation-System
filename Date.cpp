#pragma once
#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

struct date
{
    int day;
    int month;
    int year;

    date() : day(1), month(1), year(2000) {};
    date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    bool valid_date(int d, int m, int y) // to check if date is valid date or not
    {
        if (y < 0 || m < 1 || m > 12 || d < 1)
            return false;

        int last_day[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return d <= last_day[m];
    }

    void set_date(int d, int m, int y)
    {
        bool V = valid_date(d, m, y);
        if (V)
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            cout << "Invalid Date!" << nl;
            day = 1;
            month = 1;
            year = 2000;
        }
    }

    bool operator<(const date &T) const
    {
        if (year != T.year)
            return year < T.year;
        if (month != T.month)
            return month < T.month;
        return day < T.day;
    }

    void display() const
    {
        cout << setw(2) << setfill('0') << day << "/"
             << setw(2) << setfill('0') << month << "/"
             << year << endl;
    }
};

