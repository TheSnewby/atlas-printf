#include "main.h"

int _printf(const char *format, ...)
{
	va_list identifiers;
	int i;
	int print_count = 0;

	va_start(identifiers, format);
for (i = 0; format [i] != '\0'; i++)
{
	if (format[i] == '%' && format [i + 1] == '%')

{
	write(1, '%', 1);
	print_count += 1;
	i++;
}
else if (format[i] == '%' && (format[i + 1] == "c" || format[i + 1] == 's')
}
{
	print_count += percent(format[i + 1], va_arg(identifiers, char *));
	i++;
}
va_end(identifiers);
return (print_count);
}
