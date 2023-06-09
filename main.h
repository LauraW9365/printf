#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


int print_percent(va_list args);
int print_string(va_list args);
int print_character(va_list args);
int get_flags(const char *format, int *i);
int handle_write_char(char c, char buf[], int flags, int w, int pr, int sz);
int get_precision(const char *format, int *i, va_list arg);
int print_unsigned(va_list ar, char buf[], int fg, int w, int pr, int s);
int print_rot13(va_list q);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list arg);
int get_flag(char st, int *j);
int get_flag(char st, int *j);
int _printf(const char *format, ...);
int print_binary(va_list arg, char buf[], int fg, int w, int pr, int sz);
int _putchar(char c);
int prints_reverse(va_list x, char *p);
int put_s(char *s);

#endif
