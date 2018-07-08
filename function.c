/*
    Simple terminal calculator
    Copyright (C) 2018  Ludvig Blomkvist  <ludblom@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
