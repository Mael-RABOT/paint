/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** main
*/

#include "../include/prototype.h"

int main(int ac, char **av)
{
    bool_t welcome = check_welcome(ac, av);
    bool_t save = check_save(ac, av);
    bool_t tips = check_tips(ac, av);
    srand((unsigned )time(0));
    int parser_output = parser(ac, av);
    if (parser_output == 2)
        return (EXIT_SUCCESS);
    if (parser_output == EXIT_FAILURE)
        return (paint(NULL, welcome, save, tips));
    return (paint(av[ac - 1], welcome, save, tips));
}
