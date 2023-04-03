/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-yohann.mangenot
** File description:
** my_putnbr
*/

#include "prototype.h"

int my_putnbr(int number)
{
    char *buffer = malloc(nb_size(number) + 1);
    int i = 0;
    buffer[0] = '\0';
    while (number >= 1) {
        buffer[i] = (number % 10) + 48;
        number /= 10;
        i += 1;
    }
    buffer[i] = '\0';
    write(1, buffer, i + 1);
    return 0;
}
