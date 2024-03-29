#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
  int i;
  int j;
  int backIter;
  int frontIter;
  int result=1;
  char backChar;
  char frontChar;

  for (i=1;i<argc;i++) {
    backIter = strlen(argv[i])-1;
    frontIter = 0;
    for (j=0;j<strlen(argv[i]);j++) {
      backChar = argv[i][backIter];
      frontChar = argv[i][frontIter];
      if (tolower(frontChar) != tolower(backChar)) {
        result=0;
        break;
      }
      backIter--;
      frontIter++;
    }
    if (result) {
      printf("\"%s\": on palindromi\n", argv[i]);
    } else {
      printf("\"%s\": ei ole palindromi\n", argv[i]);
    }
    result=1;
  }
  return 0;
}
