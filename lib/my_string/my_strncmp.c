/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_strncmp
*/

#include "my_string.h"

int my_strncmp(const char *str_1, const char *str_2, int n)
{
    int i = 0;
    while (i < n) {
        if (str_1[i] != str_2[i])
            return (str_1[i] - str_2[i]);
        i += 1;
    }
    return 0;
}
