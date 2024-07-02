#include "main.h"
/**
 * _printf - prints a formatted string
 * @format: string with specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list identifiers; /* create empty list */
	int i; /* index var */
	int print_count = 0; /* # of chars to be printed */

	va_start(identifiers, format); /* initialize list with values after format */
	for (i = 0; format[i] != '\0'; i++) /* iterate through format until end */
	{
		if (format[i] == '%') /* special char */
		{
			if (format[i + 1] == '%')
				print_count += percent_cs(format[i + 1], NULL, 0);
			else if (format[i + 1] == 'c')
				print_count += percent_cs((char)va_arg(identifiers, int), NULL, 0);
			else if (format[i + 1] == 's')
				print_count += percent_cs('\0', va_arg(identifiers, char *), 1);
			else if (format[i + 1] == 'i')
				print_count += percent_i(va_arg(identifiers, int));
			else if (format[i + 1] == 'd')
				print_count += percent_d(va_arg(identifiers, int));
			if (format[i + 1] == '%' || format[i + 1] == 'c' ||
			format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'i')
				i++;
			else if (format[i + 1] == '\0') /* case for % not followed by specificier */
			{
				return (-1); /* error */
			}
			else
			{
				write(1, &format[i], 1); /* print '%' character if allowed */
				print_count++;
			}
		}
		else
		{
			write(1, &format[i], 1); /* print allowed characters */
			print_count++;
		}
	}
	va_end(identifiers); /* end list */
	return (print_count); /* return number of chars printed */
}
