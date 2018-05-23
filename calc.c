#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double parseFormula();
double parseSum();
double parseProduct();
double parseFactor();
double parseNumber();

char * x;

double
parseFormula()
{
  double result = parseSum();
  if(*x == '\0')
    {
      return result;
    }
  printf("Error: Something went wrong in parseFormula()");

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
  double left = parseFactor();
  while(*x == '*')
    {
      ++x;
      double right = parseFactor();
      left *= right;
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

int
main(int argc, char* argv[])
{
  x = argv[1];
  double result = parseFormula();
  printf("%lf\n", result);
  return 0;
}
