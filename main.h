#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int print_percent(va_list args);
int print_string(va_list args);
int print_character(va_list args);
int get_flags(const char *format, int *i);
int handle_write_char(char c, char buf[],
        int flags, int w, int pr, int sz);
int get_precision(const char *format, int *i, va_list arg);
int print_unsigned(va_list ar, char buf[],
        int fg, int w, int pr, int s);
int print_rot13(va_list q);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list arg);
int get_flag(char st, int *j);
int get_flag(char st, int *j);
int _printf(const char *format, ...);
int print_binary(va_list arg, char buf[],
        int fg, int w, int pr, int sz);
int _putchar(char c);
int prints_reverse(va_list x);


#endif
