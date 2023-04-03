/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strcmp
*/

#include "my_string.h"

int my_strcmp(const char *str_1, const char *str_2)
{
    int len_1 = my_strlen(str_1);
    int len_2 = my_strlen(str_2);
    int len = (len_1 < len_2) ? len_1 : len_2;
    len += 1;
    int i = 0;
    while (i < len) {
        if (str_1[i] != str_2[i])
            return (str_1[i] - str_2[i]);
        i += 1;
    }
    return 0;
}
