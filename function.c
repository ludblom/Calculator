#include <stdio.h>
#include <stdlib.h>

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
functionParser(char *start, char *end, char *x, RETURN funk)
{  
  int startInt = parseInt(start);
  int endInt = parseInt(end);
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
      //TODO: Only work for one digit, non negative, numbers. Check convert.c
      char value[16];
      sprintf(value, "%d", i);
      char *tmp = convert(value, x);

      // Calculate the product or sum
      switch(funk)
	{
	case SUM:
	  endVal += parseFormula(tmp);
	  break;
	case PRODUCT:
	  endVal *= parseFormula(tmp);
	  break;
	}
      
      free(tmp);
    }
  return endVal;
}
