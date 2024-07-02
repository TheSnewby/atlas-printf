#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int _printf(const char *, ...); /* limited printf */
int percent_cs(char, char *, int); /* handles and prints %c and %s */
int percent_d(int); /* handles %d */
int percent_i(int); /* handles %i */
void print_percent_di(int d, int i, int choice); /* recursively prints %d & %i */

#endif
