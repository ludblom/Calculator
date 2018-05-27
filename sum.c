#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "convert.h"

int
parseInt(char *x)
{
  int number;
  
  while(*x >= '0' && *x <= '9')
    {
      number = number * 10;
      number = number + *x - '0';
      ++x;
    }
  return number;
}

double
sum(char *start, char *end, char *x)
{  
  int startInt = parseInt(start);
  int endInt = parseInt(end);
  double sum = 0;
  
  for(int i = startInt; i <= endInt; i++)
    {
      char *tmp = convert(i, x);
      sum += parseFormula(tmp);
      free(tmp);
    }
  return sum;
}
