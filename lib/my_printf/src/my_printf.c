/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf.c
*/

#include "../include/prototype.h"

static int mp_detect_specifier(const char *format, va_list list, int specifier)
{
    switch (specifier) {
        case 99:
            return (mp_putchar(va_arg(list, int)));
        case 100:
            return mp_putnbr(va_arg(list, int));
        case 102:
            return mp_putfloat((float)va_arg(list, double));
        case 105:
            return mp_putnbr(va_arg(list, int));
        case 115:
            return mp_putstr(va_arg(list, char *));
        default:
            return 0;
    }
}

static int mp_format_parser(const char *format, va_list list)
{
    int i = 0;
    while (format[i] != '\0') {
        if (format[i] != 37) {
            write(1, &format[i], 1);
        } else {
            mp_detect_specifier(format, list, format[i + 1]);
            i += 1;
        }
        i += 1;
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    mp_format_parser(format, list);
    va_end(list);
    return 0;
}
