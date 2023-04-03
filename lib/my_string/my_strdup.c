/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strdup
*/

#include "my_string.h"

char *my_strdup(const char *src)
{
    int len = my_strlen(src);
    char *buffer = malloc(len);
    buffer[0] = '\0';
    int i = 0;
    while (*(src + i) != '\0') {
        *(buffer + i) = *(src + i);
        i += 1;
    }
    *(buffer + i) = '\0';
    return buffer;
}
