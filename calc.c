#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

char * x;

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
