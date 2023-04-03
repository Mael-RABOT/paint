/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** layer_management.c
*/

#include "../../include/prototype.h"

int count_layer(layer_t *layer)
{
    int count = 0;
    while (layer != NULL) {
        layer = layer->next_layer;
        count += 1;
    }
    return count;
}
