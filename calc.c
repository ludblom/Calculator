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
#include <string.h>

#include "calc.h"

char * x;

// Go through the hirarchy untill '\0' is reached, evaluating
// the expression along the way
double
parseFormula(char *init)
{
  x = init;
  double result = parseSum();
  if(*x == '\0')
    {
      return result;
    }
  printf("Error: Something went wrong in parseFormula()");
  exit(1);
}

double
parseSum()
{
  double left = parseProduct();
  while(*x == '+')
    {
      ++x;
      double right = parseProduct();
      left += right;
    }
  return left;
}

double
parseProduct()
{
  double left = parseDivision();
  while(*x == '*')
    {
      ++x;
      double right = parseDivision();
      left *= right;
    }
  return left;
}

double
parseDivision()
{
  double left = parseFactor();
  while(*x == '/')
    {
      ++x;
      double right = parseFactor();
      left /= right;
    }
  return left;
}

double
parseFactor()
{
  if(*x >= '0' && *x <= '9')
    {
      return parseNumber();
    }
  else if(*x == '(')
    {
      ++x; // Consume (
      double sum = parseSum();
      ++x; // Consume )
      return sum;
    }
  else
    {
      printf("Error: Character \"%c\" entered.\n", *x);
      exit(1);
    }
}

double
parseNumber()
{
  double number = 0;
  while(*x >= '0' && *x <= '9')
    {
      number = number * 10;
      number = number + *x - '0';
      ++x;
    }
  if(*x == '.')
    {
      ++x;
      double weight = 1;
      while(*x >= '0' && *x <= '9')
	{
	  weight = weight / 10;
	  double scale = (*x - '0') * weight;
	  number += scale;
	  ++x;
	}
    }
  return number;
}
