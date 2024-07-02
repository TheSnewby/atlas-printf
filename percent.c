#include "main.h"

/**
 * percent_cs - prints characters and strings
 * @c: individual character
 * @arg: string
 * @choice: int, 0 if char, 1 if string
 *
 * Return: number of characters printed
 */
int percent_cs(char c, char *arg, int choice)
{
	int i;
	char *cs; /* placeholder for misc. prints */

	if (choice == 0) /* print char */
	{
		write(1, &c, 1);
		return (1);
	}
	else if (choice == 1) /* print string */
	{
		if (arg == NULL)/* null string */
		{
			cs = "(null)";
			write(1, cs, 6);
			return (6);
		}
		else /* regular string */
		{
			for (i = 0; arg[i] != '\0'; i++) /* find length of string */
				;
			write(1, arg, i);
				return (i);
		}
	}
	else if (c == '%')
	{
		cs = "%"; /* print a % if %% */
		write(1, cs, 1);
		return (1);
	}
	return (0);
}
/**
 * print_percent_di - recursively prints a number depending on inputs
 * @d: int
 * @i: unsigned int
 * @choice: int, 0 for int, 1 for unsigned int
 *
 * Return: void
 */
void print_percent_di(int d, int i, int choice) /* reduceable to one param */
{
	char c;

	if (choice == 0) /* %d case, can be combined with %i */
	{
		if (d < 0) /* change sign, print '-' */
		{
			c = '-';
			write(1, &c, 1);
			d *= -1;
		}
		if (d >= 10) /* recursively call until a single digit */
			print_percent_di(d / 10, 0, 0);
		c = d % 10 + '0'; /* ones-digit assigned to character */
		write(1, &c, 1);
	}
	else /* %i case , can be combined with %d */
	{
		if (i < 0) /* change sign, print '-' */
		{
			c = '-';
			write(1, &c, 1);
			i *= -1;
		}
		if (i >= 10) /* recursively call until a single digit */
			print_percent_di(0, i / 10, 0);
		c = i % 10 + '0'; /* ones-digit assigned to character */
		write(1, &c, 1);
	}
}
/**
 * percent_i - handles %i
 * @i: integer
 *
 * Return: int, number of chars printed
 */
int percent_i(int i)
{
	int copy_i = i; /* used in finding size of i to be printed */
	int print_count = 0; /* number of chars to be printed */
	char c; /* useful for printing individual chars */

	if (copy_i == INT_MIN) /* INT_MIN case */
	{
		copy_i = copy_i / 10;
		print_count++;
	}
	if (copy_i < 0) /* remove negative while adding print counter */
	{
		copy_i *= -1;
		print_count++;
	}
	else if (copy_i == 0) /* makes sure 0 is counted */
		print_count++;
	while (copy_i > 0) /* finds remaining values to be printed */
	{
		copy_i = copy_i / 10;
		print_count++;
	}
	if (i != INT_MIN) /* print non-INT_MIN cases */
		print_percent_di(i, 0, 0);
	else
	{
		print_percent_di(i / 10, 0, 0); /* print INT_MIN case */
		c = 8 + '0'; /* hard-coding the first ones-digit of INT_MIN */
		write(1, &c, 1);
	}

	return (print_count);
}

/**
 * percent_d - handles %d
 * @d: decimal
 *
 * Return: int, number of chars printed
 */
int percent_d(int d) /* consider combining with percent_i */
{
	int copy_d = d; /* same notes as for percent_i */
	int print_count = 0;
	char c;

	if (copy_d == INT_MIN)
	{
		copy_d = copy_d / 10;
		print_count++;
	}
	if (copy_d < 0)
	{
		copy_d *= -1;
		print_count++;
	}
	else if (copy_d == 0)
		print_count++;
	while (copy_d > 0)
	{
		copy_d = copy_d / 10;
		print_count++;
	}
	if (d != INT_MIN)
		print_percent_di(d, 0, 0);
	else
	{
		print_percent_di(d / 10, 0, 0);
		c = 8 + '0'; /* hard-coding the first digit of INT_MIN */
		write(1, &c, 1);
	}

	return (print_count);
}
