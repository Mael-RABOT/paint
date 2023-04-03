/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_revstr
*/

#include "my_string.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    int j = len - 1;
    int middle = len / 2;
    while (i < middle) {
        char tmp = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = tmp;
        i += 1;
        j -= 1;
    }
    return str;
}
