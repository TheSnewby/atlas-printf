#include "main.h"

/**
 * percent_cs - prints characters and strings
 * @c: individual character
 * @s: string
 *
 * Return: number of characters printed
 */
int percent_cs(char c, char *arg) /* combined to make room for more functions */
{
    int i;

    if (c == '\0' && arg == NULL)
        return (0);
    else if (arg != NULL) /* print string */
    {
        for (i = 0; arg[i] != '\0'; i++)
            ;
        write(1, arg, i);
        return (i);
    }
    else if (c != '\0') /* print char */
    {
        write(1,&c,1);
        return(1);
    }
    return (0);
}

/**
 * percent_i - prints an unsigned int recursively
 * @i: unsigned int
 *
 * Return: void
 */
void percent_i(unsigned int i)
{
    char c;
    if (i >= 10)
        percent_i(i / 10);
    c = i % 10 + '0';
    write(1, &c, 1);
}

/**
 * percent_d - prints an int recursively
 * @d: int
 *
 * Return: void
 */
void percent_d(int d)
{
    char c;
    if (d < 0)
    {
      c = '-';
      write(1, &c, 1);
      d *= -1;
    }
    if (d >= 10)
        percent_d(d / 10);
    c = d % 10 + '0';
    write(1, &c, 1);
}
