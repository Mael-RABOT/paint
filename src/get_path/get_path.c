/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** get_path
*/

#include "../../include/prototype.h"

static int line_length(const char *str)
{
    int len = 0;
    while (*(str + len++) != '\0');
    return len;
}

char *get_path(path_type_t type)
{
    char *line = NULL;
    size_t len;
    if (type == SAVE)
        my_printf("Choose the path to save the image: ");
    if (type == LOAD)
        my_printf("Choose the path to load the image: ");
    if (getline(&line, &len, stdin) == -1)
        return (STD_FILE_PATH);
    line[line_length(line) -2] = (line[line_length(line) -2] == '\n')
        ? '\0' : line[line_length(line) -2];
    return (line);
}
