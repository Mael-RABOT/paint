/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** mp_putfloat
*/

#include "../include/prototype.h"

static float get_right_part(float number)
{
    float right_part = number;
    right_part -= (int)right_part;
    if (right_part < 0)
        right_part *= -1;
    return right_part;
}

int mp_putfloat(float number)
{
    mp_putnbr((int)number);
    float right_part = get_right_part(number);
    int i = 0;
    while (i < 6) {
        right_part *= 10;
        i += 1;
    }
    mp_putchar('.');
    mp_putnbr((int)right_part);
    return 0;
}
