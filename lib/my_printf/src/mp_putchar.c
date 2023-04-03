/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** mp_putchar
*/

#include "../include/prototype.h"

int mp_putchar(char character)
{
    write(1, &character, 1);
    return 0;
}
