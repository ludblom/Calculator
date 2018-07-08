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

#include "calc.h"
#include "convert.h"
#include "function.h"
#include "functionUsed.h"

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

  // Todo: More work nedded in function.c and convert.c to support all numbers
  // and negative numbers
  
  switch(*argv[1])
    {
    case 'S':
      // functionParser in function.c.
      // Parse the function and later pass that function with values to
      // parseFormula in calc.c
      result = functionParser(argv[2], argv[3], argv[4], SUM);      
      break;
    case 'P':
      result = functionParser(argv[2], argv[3], argv[4], PRODUCT);
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
