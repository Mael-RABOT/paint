/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** save_image
*/

#include "../../include/prototype.h"

static int end_with(const char *src, const char *str)
{
    for (int i = 0; i < 4; i++)
        if (src[my_strlen(src) - 1 - i] != str[my_strlen(str) - 1 - i])
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int as_filetype(filetype_t filetype, char *path)
{
    switch (filetype) {
        case png:
            return (end_with(path, ".png"));
        case jpg:
            return (end_with(path, ".jpg"));
        case bpm:
            return (end_with(path, ".bpm"));
        default:
            return (end_with(path, ".png"));
    }
}

static char *file_extension(filetype_t filetype)
{
    switch (filetype) {
        case png:
            return (".png");
        case jpg:
            return (".jpg");
        case bpm:
            return (".bpm");
        default:
            return (".png");
    }
}

static char *add_file_extension(app_t *app, char *path)
{
    char *new_path = malloc(sizeof(char) * my_strlen(path) + 10);
    my_strcpy(new_path, path);
    my_strcat(new_path, file_extension(app->filetype));
    return (new_path);
}

int save_image(app_t *app)
{
    char *path;
    if (app->overwrite == TRUE || !app->save_path)
        path = get_path(SAVE);
    else
        path = app->save_path;
    if (as_filetype(app->filetype, path) == EXIT_FAILURE)
        path = add_file_extension(app, path);
    app->save_path = path;
    my_printf("path: %s\n", app->save_path);
    concat_layer(app);
    set_title(app, app->save_path);
    app->is_save = 1;
    return (EXIT_SUCCESS);
}
