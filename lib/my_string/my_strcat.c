/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strcat
*/

#include "my_string.h"

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int len = my_strlen(dest);
    while (*(src + i) != '\0') {
        *(dest + len + i) = *(src + i);
        i += 1;
    }
    *(dest + len + i) = '\0';
    return dest;
}
