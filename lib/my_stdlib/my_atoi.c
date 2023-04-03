/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_atoi
*/

#include "prototype.h"

static int my_atoi_extract_nb(const char *src)
{
    const char *str_nb;
    int is_neg = is_negative(src, &str_nb);
    int result = 0;
    int i = 0;
    while (*(str_nb + i) != '\0' && *(str_nb + i) != '.') {
        result = result * 10 + (str_nb[i] - 48);
        i += 1;
    }
    return result * is_neg;
}

int my_atoi(const char *src)
{
    if (check_sanity_number(src) == 0)
        return 0;
    return my_atoi_extract_nb(src);
}
