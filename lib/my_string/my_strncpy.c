/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strncpy
*/

#include "my_string.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;
    dest[0] = '\0';
    while (i < n) {
        *(dest + i) = *(src + i);
        i += 1;
    }
    *(dest + i) = '\0';
    return dest;
}
