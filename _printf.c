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
  unsigned int original_i;
  unsigned int copy_i;
  int original_d;
  int copy_d;
  
  va_start(identifiers, format);
  for (i = 0; format[i] != '\0'; i++)
  {
    if (format[i] == '%' && format [i + 1] == '%')
    {
      write(1, '%', 1);
      print_count += 1;
      i++;
    }
    else if (format[i] == '%' && (format[i + 1] == 'c'))
    {
      print_count += percent_cs((char)va_arg(identifiers, int), '\0');
    }
    else if (format[i] == '%' && (format[i + 1] == 's'))
    {
      print_count += percent_cs(NULL, va_arg(identifiers, char *));
    }
    else if (format[i] == '%' && (format[i + 1] == 'i'))
    {
      original_i = va_arg(identifiers, unsigned int);
      copy_i = original_i;
      
      while (copy_i > 0)
      {
          copy_i = copy_i / 10;
          print_count++;
      }
       percent_i(original_i);
    }
    else if (format[i] == '%' && (format[i + 1] == 'd'))
    {
      original_d = va_arg(identifiers, int);
      copy_d = original_d;
      if (copy_d < 0)
      {
          copy_d *= -1;
          print_count++;
      }
      while (copy_d > 0)
      {
          copy_d = copy_d / 10;
          print_count++;
      }
       percent_d(original_d * -1);
    }
    i++;
  }
  va_end(identifiers);
  return (print_count);
}
