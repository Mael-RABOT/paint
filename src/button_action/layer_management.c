/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** layer_management.c
*/

#include "../../include/prototype.h"

void add_layer(app_t *app, int status)
{
    layer_t *layer = app->canvas->layer;
    layer_t *new_layer = append_layer(layer);
    app->canvas->selected_layer = new_layer;
    append_object(app->ui_button->layer_preview, WHITE, &do_nothing);
}

void delete_layer(app_t *app, int status)
{
    if (count_layer(app->canvas->layer) == 1)
        return;
    layer_t *layer = app->canvas->selected_layer;
    layer_t *tmp_layer = app->canvas->layer;
    int index = 0;
    while (tmp_layer->next_layer != layer) {
        index += 1;
        tmp_layer = tmp_layer->next_layer;
    }
    free_one_object(app->ui_button->layer_preview, index);
    tmp_layer->next_layer = layer->next_layer;
    app->canvas->selected_layer = tmp_layer;
    free_layer(layer);
}
