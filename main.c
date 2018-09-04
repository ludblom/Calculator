#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "convert.h"
#include "function.h"
#include "functionUsed.h"

int
main(int argc, char* argv[])
{
  double result;
  int start, end;

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

  // Todo: More work nedded in function.c and convert.c to support all numbers
  // and negative numbers
  
  switch(*argv[1])
    {
    case 'S':
      // functionParser in function.c.
      // Parse the function and later pass that function with values to
      // parseFormula in calc.c
      start = (int)strtod(argv[2], 0);
      end = (int)strtod(argv[3], 0);
      result = functionParser(start, end, argv[4], SUM);      
      break;
    case 'P':
      result = functionParser((int)strtod(argv[2], 0), (int)strtod(argv[3], 0), argv[4], PRODUCT);
      break;
    default:
      // Pure mathematical expression or error
      result = parseFormula(argv[1]);
      break;
    }

  // Print result
  printf("%lf\n", result);
  return 0;
}
