/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strcpy
*/

#include "my_string.h"

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    dest[0] = '\0';
    while (*(src + i) != '\0') {
        *(dest + i) = *(src + i);
        i += 1;
    }
    *(dest + i) = '\0';
    return dest;
}
