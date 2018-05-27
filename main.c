#include <stdio.h>

#include "calc.h"
#include "sum.h"

#include "convert.h"

int
main(int argc, char* argv[])
{
  double result;  
  switch(*argv[1])
    {
    case 'h':
      printf("Print help or something\n");
      break;
    case 'S':
      // Todo: More work nedded in sum.c and convert.c, se TODO's
      result = sum(argv[2], argv[3], argv[4]);
      printf("%lf\n", result);
      break;
    default:      
      result = parseFormula(argv[1]); // Just regular expression or error
      printf("%lf\n", result);
      break;
    }
  
  /*
  char *x = "x+x";
  
  char *p = convert(1, x);
  printf("%s\n", p);
  */
  return 0;
}
