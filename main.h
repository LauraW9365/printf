#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include<stdio.h>
#include <unistd.h>


int _printf(const char *format, ...);
int _putchar(char c);
int prints_percent(va_list args);
int prints_string(va_list args);
int prints_character(va_list args);
int prints_reverse(va_list x);

#endif
