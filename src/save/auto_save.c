/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** auto_save
*/

#include "../../include/prototype.h"

void auto_save(app_t *app, bool_t save)
{
    if (!save)
        return;
    my_printf("Do you want to save the file [Y/n]");
    char *line = NULL;
    size_t len;
    getline(&line, &len, stdin);
    if (my_strcmp(line, "\n") == 0 || my_strcmp(line, "Y\n") == 0
        || my_strcmp(line, "y\n") == 0)
        save_image(app);
}
