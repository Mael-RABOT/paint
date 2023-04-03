/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** prototype
*/

#ifndef BASE_REPO_PROTOTYPE_H
    #define BASE_REPO_PROTOTYPE_H

    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include "my_stdlib.h"

    int is_negative(const char *str, const char **new_ptr);
    int check_sanity_number(const char *str);

    int nb_size(int number);
    int my_putnbr(int number);

#endif //BASE_REPO_PROTOTYPE_H
