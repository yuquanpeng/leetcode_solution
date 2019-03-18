#include <stdio.h>
#include <string.h>
#define ISYEAR(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
int dayOfMOnth[13][2] = {
    0, 0,
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31};
struct Date
{
    int Day;
    int Month;
    int Year;
    void nextDay()
    {
        Day++;
        //计算下一天的日期
        if (Day > dayOfMOnth[Month][ISYEAR(Year)])
        {
            Day = 1;
            Month++;
            if (Month > 12)
            {
                Month = 1;
                Year++;
            }
        }
    }
};
int buf[3001][13][32];
char monthName[13][20] = {
    "",
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"};
char weekName[7][20] = {
    "Sun",
    "Mon",
    "Tues",
    "Wed",
    "Thu",
    "Fri",
    "Sat"};
int main()
{
    Date tmp;
    int cnt = 0;
    tmp.Day = 1;
    tmp.Month = 1;
    tmp.Year = 0;
    while (tmp.Year != 3001)
    {
        buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
        tmp.nextDay();
        cnt++;
    }
    int d, m, y;
    char s[20];
    while (scanf("%d %s %d", &d, s, &y))
    {
        for (m = 1; m <= 12; m++)
        {
            if (strcmp(s, monthName[m]) == 0)
                break;
        }
        int days = buf[y][m][d] - buf[2019][2][28];
        days += 4;
        puts(weekName[(days % 7 + 7) % 7]);
    }
    return 0;
}