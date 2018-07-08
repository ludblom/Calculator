#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "convert.h"

char*
convert(char* value, char *x)
{
  //char val = value + '0';
  int lenOfVar = sizeof(value);
  char *str = malloc (sizeof (char) * strlen(x));
  int i = 0;

  //TODO: Add support for numbers bigger than 0-9
  //TODO: Give me wrong value with quite alot, try any 2 digit number, check function.c
  
  while(*x != '\0')
    {
      if(*x == 'x' || *x == 'X')
	{
	  for(int k = 0; k < lenOfVar; k++)
	    {
	      str = (char *) realloc(str, 10);
	      str[i+k] = value[k];
	    }	  
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
