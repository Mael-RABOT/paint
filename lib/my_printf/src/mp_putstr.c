/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** mp_putstr
*/

#include "../include/prototype.h"

static int mp_strlen(char *str)
{
    int i = 0;
    while (*(str + i) != '\0') {
        i += 1;
    }
    return i;
}

int mp_putstr(char *str)
{
    int len = mp_strlen(str);
    write(1, str, len);
    return 0;
}
