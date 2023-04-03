/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strappend
*/

#include "my_string.h"

int my_strappend(char *dest, const char character)
{
    int len = my_strlen(dest);
    *(dest + len) = character;
    *(dest + len + 1) = '\0';
    return 0;
}
