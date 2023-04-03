/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** concat_layer.c
*/

#include "../../include/prototype.h"

int concat_layer(app_t *app)
{
    sfTexture* texture = sfTexture_create(DRAWING_WIDTH, DRAWING_HEIGHT);
    layer_t *layer = app->canvas->layer;
    while (layer != NULL) {
        sfTexture_updateFromPixels(texture, layer->layer, DRAWING_WIDTH,
            DRAWING_HEIGHT, 0, 0);
        layer = layer->next_layer;
    }
    sfImage *image = sfTexture_copyToImage(texture);
    if (sfImage_saveToFile(image, app->save_path) == sfTrue)
        my_printf("File successfully save at: %s\n", app->save_path);
    else {
        sfImage_destroy(image);
        return (EXIT_FAILURE);
    }
    sfImage_destroy(image);
    sfTexture_destroy(texture);
    return 0;
}
