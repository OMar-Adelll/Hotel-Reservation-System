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

    bool valid_date(date &other) // to check if date is valid date or not  (with date)
    {
        int m = other.month, d = other.day, y = other.year;
        if (y < 0 || m < 1 || m > 12 || d < 1)
            return false;

        int last_day[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return d <= last_day[m];
    }

    bool valid_date(int d, int m, int y) // to check if date is valid date or not
    {
        if (y < 0 || m < 1 || m > 12 || d < 1)
            return false;

        int last_day[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return d <= last_day[m];
    }

    void set_date(const date &other)
    {
        set_date(other.day, other.month, other.year);
    }

    void set_date(int d, int m, int y)
    {
        while (!valid_date(d, m, y))
        {
            cout << "Please enter a valid date: ";
            cin >> d >> m >> y;
        }

        this->day = d;
        this->month = m;
        this->year = y;
    }

    bool operator<(const date &T) const
    {
        if (year != T.year)
            return year < T.year;
        if (month != T.month)
            return month < T.month;
        return day < T.day;
    }

    date &operator=(const date &other)
    {
        if (this == &other)
            return *this;

        day = other.day;
        month = other.month;
        year = other.year;

        return *this;
    }

    void display() const
    {
        cout << setw(2) << setfill('0') << day << "/"
             << setw(2) << setfill('0') << month << "/"
             << year << endl;
    }

    string toString() const
    {
        char buf[11];
        sprintf(buf, "%02d/%02d/%04d", day, month, year);
        return std::string(buf);
    }
};
