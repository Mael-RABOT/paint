/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** set_title
*/

#include "../../include/prototype.h"

void set_title(app_t  *app, char *path)
{
    char *title = malloc(sizeof(char) * (my_strlen(path) + 20));
    my_strcpy(title, "My Paint: ");
    my_strcat(title, path);
    sfRenderWindow_setTitle(app->window, title);
    free(title);
}
