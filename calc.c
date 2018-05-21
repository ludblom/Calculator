#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * x;

int parseFactor();
int parseSum();
int parseProduct();

int
parseSum()
{
  int pro1 = parseProduct();
  while(*x == '+')
    {
      ++x;
      int pro2 = parseProduct();
      pro1 = pro1 + pro2;
    }
  return pro1;
}

int
parseProduct()
{
  int fac1 = parseFactor();
  while(*x == '*')
    {
      ++x;
      int fac2 = parseFactor();
      fac1 = fac1 * fac2;
    }
  return fac1;
}

int
parseFactor()
{
  int val[200];
  int num = 0;
  int i = 0;
  if(*x >= '0' && *x <= '9')
    {
      int s = 0;
      while(*x >= '0' && *x <= '9')
	{
	  val[i] = *x++ - '0';
	  i++;
	}
      for(int k = i - 1; k >= 0; k--)
	{
	  num += val[k] * (int)pow(10.0, (double) s);
	  s++;
	}
      return num;
    }
  else if(*x == '(')
    {
      ++x; // Consume (
      int sum = parseSum();
      ++x; // Consime )
      return sum;
    }
  else
    {
      printf("Error: Character.");
    }
}

int
main(int argc, char* argv[])
{
  x = argv[1];
  int result = parseSum();
  printf("%d\n", result);
  return 0;
}
