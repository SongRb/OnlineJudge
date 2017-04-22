#include <iostream>
#include <cstdio>

using namespace std;

int dayInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayBeforeMonth[13];

bool runnian(int y)
{
    if (y % 400 == 0) return true;
    else if (y % 4 == 0 && y % 100 != 0) return true;
    else return false;
};

int getDayBeforeMonth(int m, int y)
{
    if (runnian(y))
    {
        if (m <= 2) return dayBeforeMonth[m];
        else return dayBeforeMonth[m] + 1;
    } else
    {
        return dayBeforeMonth[m];
    }

};

int getDayInMonth(int m, int y)
{
    if (runnian(y))
    {
        if (m == 2) return dayInMonth[m] + 1;
        else return dayInMonth[m];
    } else
    {
        return dayInMonth[m];
    }
}

// dayExtra[0] 指的是1851年1月1日的偏移量
int dayExtra[202];

int main()
{
    int month, week, day, y1, y2;
    cin >> month >> week >> day >> y1 >> y2;

    int days = 0;
    for (int i = 1850; i <= 2050; i++)
    {
        days += 1;
        days += runnian(i);
        dayExtra[i - 1850 + 1] = days % 7;
    }

    for (int i = 1; i <= 12; i++)
    {
        dayBeforeMonth[i] = 0;
        if (i > 2) dayBeforeMonth[i] = dayBeforeMonth[i - 1] + dayInMonth[i - 1];
        if (i == 2) dayBeforeMonth[2] = dayInMonth[1];
        if (i == 1) dayBeforeMonth[1] = 0;
    }


    for (int i = y1; i <= y2; i++)
    {
        int tmp = dayExtra[i - 1850] + getDayBeforeMonth(month, i);
        // tmp 指的是1号星期几
        tmp = (tmp + 2) % 7;
        if (tmp == 0) tmp = 7;


        // tian 指的是第一个星期几
        int tian;
        if (day >= tmp) tian = day - tmp + 1;
        else tian = 7 + day - tmp + 1;

        int finalDay = 0;
        finalDay = tian + (week - 1) * 7;

        if (finalDay > getDayInMonth(month, i)) cout << "none" << endl;
        else
        {
            printf("%d/", i);
            printf("%02d", month);
            printf("/%02d", finalDay);
            printf("\n");
        }
    }

    return 0;
}

