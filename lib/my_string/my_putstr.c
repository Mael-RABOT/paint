/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_putstr
*/

#include "my_string.h"

int my_putstr(const char *str)
{
    int i = 0;
    while (*(str + i) != '\0') {
        my_putchar(*(str + i));
        i += 1;
    }
    return 0;
}
