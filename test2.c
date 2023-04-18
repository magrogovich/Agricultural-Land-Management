#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time = time(NULL);   // get the current time in seconds
    struct tm *local_time = localtime(&current_time);   // convert to local time

    int year = local_time->tm_year + 1900;   // years since 1900
    int month = local_time->tm_mon + 1;      // months since January (0-11)
    int day = local_time->tm_mday;           // day of the month (1-31)

    printf("Today is %04d-%02d-%02d\n", year, month, day);

    return 0;
}
