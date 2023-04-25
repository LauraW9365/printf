#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int prints_percent(va_list args);
int prints_string(va_list args);
int prints_character(va_list args);
int prints_reverse(va_list x);
int print_rot13(va_list q);
int printhexa_upper(va_list arg, char map_to[], char buf[],
	int fg, char flag_ch, int w, int pr, int sz);
int printhexa_upper(va_list arg, char buf[],
	int fg, int w, int pr, int sz);
int prints_octal(va_list arg, char buf[],
	int fg, int w, int pr, int sz);
int print_unsigned(va_list ar, char buf[],
	int fg, int w, int pr, int sz);
int print_binary(va_list arg, char buf[],
	int fg, int w, int pr, int sz);
int print_int(va_list arg, char buf[],
	int fg, int w, int pr, int sz);
#endif
