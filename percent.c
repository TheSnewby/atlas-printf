#include "main.h"

/**
 * percent - handles the percent sign in _printf strings
 * @id: character directly after %; acts as identifier
 * @arg: passed argument for specifier
 *
 * Return: # of characters printed
 */

int percent(char id, char *arg)
{
	int i;

	if (i == 'c')
	{
		write(1,arg,1);
		return(1);
	}
	/* might need to isolate 's' and call _printf from it */
	else if (i == 's' || i == 'd' || i == 'i')
	{
		for (i = 0; arg[i] != '\0'; i++)
			;
		write(1, arg, i);
		return(i);
	}
	else if (i == '%')
	{
		write(1, '%', 1);
		return (1);
	}
	else
		return(0);
}
