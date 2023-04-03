/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_ato*_globalf
*/

#include "prototype.h"

static int is_a_mathematical_char(const char character)
{
    if (character == 45 || character == 43 || character == 46)
        return 1;
    if (character >= 48 && character <= 57)
        return 1;
    return 0;
}

int check_sanity_number(const char *str)
{
    int i = 0;
    while (*(str + i) != '\0') {
        if (is_a_mathematical_char(*(str + i)) == 0)
            return 0;
        i += 1;
    }
    return 1;
}

int nb_size(int number)
{
    int i = 1;
    if (number < 0)
        number *= -1;
    while (number >= 10) {
        number /= 10;
        i += 1;
    }
    return i;
}

int is_negative(const char *str, const char **new_ptr)
{
    int i = 0;
    int is_negative = 0;
    while (*(str + i) < 48 || *(str + i) > 57) {
        if (*(str + i) == 45) {
            is_negative = 1 - is_negative;
        }
        i += 1;
    }
    *new_ptr = &str[i];
    if (is_negative == 0)
        return 1;
    else
        return -1;
}
