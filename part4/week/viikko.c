#include "viikko.h"
#include <time.h>
#include <stdio.h>

#define DATE_STRING_MAX 100

int MONTH_LENS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get_day_number(int day, int month, int year) {
  int k,j,dayOfWeek;
  if (month < 3) {
      month += 12;
      year--;
  }

  k = year % 100;
  j = year / 100;

  dayOfWeek = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

  return (dayOfWeek + 5) % 7 ;
}

struct tm create_date(int day, int month, int year) {
  int dayPass;
  struct tm date;
  dayPass = get_day_number(day,month,year);

  date.tm_mday = day;
  date.tm_mon = month-1;
  date.tm_year = year-1900;
  date.tm_wday = dayPass+1;

  return date;
}

void viikko(int day, int month, int year) {
  char printStr[DATE_STRING_MAX];
  int i;
  int dayNumber = get_day_number(day,month,year);
  int isLeap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  struct tm date;

  if(isLeap) {
    MONTH_LENS[1]=29;
  }

  if(day > dayNumber) {
    day -= dayNumber;
  /* week starts at prev month */
  } else {
    /* prev month in prev year */
    if(month-1==0) {
      month=12;
      year--;
    } else {
      month -=1;
    }
    day = MONTH_LENS[month-1]-(dayNumber-day);
  }

  for(i=0;i<7;i++) {    
    date = create_date(day,month,year);
    /* sunday is 0 */
    if(i==6) {
      date.tm_wday=0;
    }

    strftime(printStr,DATE_STRING_MAX,"%A %d. %B %Y",&date);

    printf("%s\n",printStr);
    day++;
    if(day > MONTH_LENS[month-1]) {
      month++;
      if(month > 12) {
        month = 1;
        year++;
      }
      day = 1;
    }
  }
  return;
}
