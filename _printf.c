#include "main.h"
/**
 * _printf - prints a formatted string
 * @format: string with specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list identifiers;
	int i;
	int print_count = 0;

	va_start(identifiers, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				print_count += percent_cs(format[i + 1], NULL, 0);
			else if (format[i + 1] == 'c')
				print_count += percent_cs((char)va_arg(identifiers, int), NULL, 0);
			else if (format[i + 1] == 's')
				print_count += percent_cs('\0', va_arg(identifiers, char *), 1);
			else if (format[i + 1] == 'i')
				print_count += percent_i(va_arg(identifiers, unsigned int));
			else if (format[i + 1] == 'd')
				print_count += percent_d(va_arg(identifiers, int));
			if (format[i + 1] == '%' || format[i + 1] == 'c' ||
			format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'i')
				i++;
			else /* case for % not followed by specificier */
				continue;
		}
		else
		{
			write(1, &format[i], 1);
			print_count++;
		}
	}
	va_end(identifiers);
	return (print_count);
}
