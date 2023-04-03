/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strlen
*/

#include "my_string.h"

int my_strlen(const char *str)
{
    int len = 0;
    while (*(str + len) != '\0') {
        len += 1;
    }
    return len;
}
