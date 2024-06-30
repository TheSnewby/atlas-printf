#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int _printf(const char *, ...);
int percent_cs(char, char *, int);
int percent_d(int);
int percent_i(unsigned int);
void print_percent_di(int d, unsigned int i, int choice);

#endif
