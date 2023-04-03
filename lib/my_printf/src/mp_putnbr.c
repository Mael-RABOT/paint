/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** mp_putnbr
*/

#include "../include/prototype.h"

static int mp_check_exception(int number)
{
    char character;
    if (number < 10 && number >= 0) {
        character = number + 48;
        write(1, &character, 1);
        return 1;
    }
    if (number > -10 && number < 0) {
        write(1, "-", 1);
        number *= -1;
        character = number + 48;
        write(1, &character, 1);
        return 1;
    }
    return 0;
}

static int mp_nbsize(int number)
{
    int size = 1;
    while (number >= 10) {
        size += 1;
        number /= 10;
    }
    return size;
}

int mp_writenbr(int number)
{
    int size = mp_nbsize(number);
    char *buffer = malloc(size + 1);
    buffer[size] = '\0';
    int i = 0;
    while (i < size) {
        buffer[size - i - 1] = number % 10 + 48;
        number /= 10;
        i += 1;
    }
    write(1, buffer, size);
    free(buffer);
    return 0;
}

int mp_putnbr(int number)
{
    if (mp_check_exception(number) == 1)
        return 0;
    if (number < 0) {
        number *= -1;
        write(1, "-", 1);
    }
    mp_writenbr(number);
    return 0;
}
