/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** parser
*/

#include "../include/prototype.h"

int display_help(void)
{
    char *line = NULL;
    size_t len;
    FILE *file_stream = fopen(HELP_FILE, "r");
    while (getline(&line, &len, file_stream) >= 0)
        my_printf("%s", line);
    return (2);
}

int parser(int ac, char **av)
{
    if (ac == 1)
        return (EXIT_FAILURE);
    if (my_strcmp(av[1], "-h") == EXIT_SUCCESS)
        return (display_help());
    else {
        int fd = open(av[ac - 1], O_RDONLY);
        if (fd == -1)
            return (EXIT_FAILURE);
        else
            return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}

bool_t check_save(int ac, char **av)
{
    bool_t save = TRUE;
    for (int i = 0; i < ac; i++)
        if (my_strcmp(av[i], "--no-save") == EXIT_SUCCESS)
            save = FALSE;
    return (save);
}

bool_t check_welcome(int ac, char **av)
{
    bool_t welcome = TRUE;
    for (int i = 0; i < ac; i++)
        if (my_strcmp(av[i], "--no-welcome") == EXIT_SUCCESS)
            welcome = FALSE;
    return (welcome);
}

bool_t check_tips(int ac, char **av)
{
    bool_t tips = TRUE;
    for (int i = 0; i < ac; i++)
        if (my_strcmp(av[i], "--no-tips") == EXIT_SUCCESS)
            tips = FALSE;
    return (tips);
}
