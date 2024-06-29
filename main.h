#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int _printf(const char *, ...);
int percent_cs(char, char *, int);
void percent_d(int);
void percent_i(unsigned int);

#endif