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
