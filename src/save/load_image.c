/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** load_image
*/

#include "../../include/prototype.h"

void update_loaded_file(app_t *app)
{
    sfColor color = (sfColor){app->canvas->layer->layer[0],
        app->canvas->layer->layer[1],
        app->canvas->layer->layer[2], app->canvas->layer->layer[3]};
    put_square(app->canvas, (sfVector2f){0, 0}, 1, color);
    sfTexture_updateFromPixels(app->canvas->layer->rectangle->texture,
        app->canvas->layer->layer,
        DRAWING_WIDTH, DRAWING_HEIGHT, 0, 0);
}

int load_image(app_t *app)
{
    if (app->load_path == NULL)
        app->load_path = get_path(LOAD);
    sfImage *image = sfImage_createFromFile(app->load_path);
    sfUint8 *pixels = (sfUint8*)sfImage_getPixelsPtr(image);
    if (pixels == NULL) {
        my_printf("File was empty\n");
        return (EXIT_FAILURE);
    }
    app->canvas->layer->layer = pixels;
    set_title(app, app->load_path);
    free(app->load_path);
    return (EXIT_SUCCESS);
}
