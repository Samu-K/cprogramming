#include <time.h>
#include <stdio.h>
#include <string.h>

struct DayCorrelation {
  char engName[15];
  char finName[15];
};

const char* getFinnishName(const struct DayCorrelation weekdays[], 
                            int size, const char* englishName) {
  int i=0;
  for (i = 0; i < size; ++i) {
      if (strcmp(weekdays[i].engName, englishName) == 0) {
          return weekdays[i].finName;
      }
  }
  return "Unknown";
}

struct DayCorrelation weekdays[] = {
  {"Monday", "Maanantai"},
  {"Tuesday", "Tiistai"},
  {"Wednesday", "Keskiviikko"},
  {"Thursday", "Torstai"},
  {"Friday", "Perjantai"},
  {"Saturday", "Lauantai"},
  {"Sunday", "Sunnuntai"}
};
int main(void) {
  char prntTime[30];
  char clockTime[20];
  char weekday[15];
  time_t a = time(NULL);
  struct tm *b = localtime(&a);
  strftime(weekday,15,"%A",b);
  strftime(clockTime,20,"%H:%M",b);
  strftime(prntTime,30,"%d.%m.%Y",b);

  printf("%s %s klo %s\n",
        getFinnishName(weekdays,sizeof(weekdays)/sizeof(weekdays[0]),weekday),
        prntTime,clockTime);

  return 0;
}
