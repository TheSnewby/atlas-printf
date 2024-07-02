_printf is a limited version of the printf function found in <stdio.h>.
This printing a formated string that handles:
1. %c, %s, %d, %i
2. %%
3. %d & %i with INT_MIN & INT_MAX
4. %\0 returns -1 due to undefined behavior
5. %s printing '(null)' when passed string is NULL

_printf, like printf, returns the number of characters printed.
Recursion is used in printing %d & %i.
main.h holds all libraries and prototypes used.
percent.c holds all functions.
Interestingly the print number functions and the number handlers can be refactored at some point in the future. This was not done this time due to being unsure whether we could recheck our work or not.