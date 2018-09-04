#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"
#include "convert.h"
#include "functionUsed.h"

int
parseInt(char *x)
{
  int number = 0;

  // TODO: When parsing more than one number, not actual atm

  while(*x >= '0' && *x <= '9')
    {
      number = number * 10;
      number = number + *x - '0';
      ++x;
    }

  return number;
}

double
functionParser(int startInt, int endInt, char *x, RETURN funk)
{
  double endVal;

  if(funk == PRODUCT)
    {
      endVal = 1.0;
    }
  else
    {
      endVal = 0;
    }
  
  for(int i = startInt; i <= endInt; i++)
    {
      //TODO: Ugly AF, but works
      char* value = malloc(32 * sizeof(char));
      sprintf(value, "%d", i);

      // Calculate the product or sum
      switch(funk)
	{
	case SUM:
	  endVal += parseFormula(value);
	  break;
	case PRODUCT:
	  endVal *= parseFormula(value);
	  break;
	}
      free(value);
    }
  return endVal;
}
