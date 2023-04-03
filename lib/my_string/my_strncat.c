/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strncat
*/

#include "my_string.h"

char *my_strncat(char *dest, const char *src, int n)
{
    int i = 0;
    int len = my_strlen(dest);
    while (i < n) {
        *(dest + len + i) = *(src + i);
        i += 1;
    }
    *(dest + len + i) = '\0';
    return dest;
}
