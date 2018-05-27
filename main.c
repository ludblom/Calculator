#include <stdio.h>

#include "calc.h"
#include "function.h"

#include "convert.h"
#include "functionUsed.h"

#include <string.h>

int
main(int argc, char* argv[])
{
  double result;

  if(argc == 1)
    {
      // TODO!
      printf("Usage: calc [Function] [Start] [End] [Expression]\n");
      printf("\t--[Function]:\n");
      printf("\t\tS - Sum all values from Start to End\n");
      printf("\t\tP - Product all values from Start to End\n");
      printf("\t--[Start]: Integer value\n");
      printf("\t--[End]: Integer value\n");
      printf("\t--[Expression]:\n");
      printf("\t\tP or S, use x as variable in [Expression]\n");
      printf("\t\tRegular use, calc [Expression]\n");
      return 1;
    }
  
  switch(*argv[1])
    {
    case 'S':
      // Todo: More work nedded in function.c.c and convert.c to support all numbers
      // and negative numbers
      result = functionParser(argv[2], argv[3], argv[4], SUM);      
      break;
    case 'P':
      result = functionParser(argv[2], argv[3], argv[4], PRODUCT);
      break;
    default:
      result = parseFormula(argv[1]); // Just regular expression or error
      break;
    }
  
  printf("%lf\n", result);
  return 0;
}
