#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "convert.h"

char*
convert(int value, char *x)
{
  char val = value + '0';
  char *str = malloc (sizeof (char) * strlen(x));
  int i = 0;

  //TODO: Add support for numbers bigger than 0-9
  
  while(*x != '\0')
    {
      if(*x == 'x' || *x == 'X')
	{
	  str[i] = val;
	}
      else
	{
	  str[i] = *x;
	}
      ++x;
      ++i;
    }

  str[i] = *x;

  return str;
}
