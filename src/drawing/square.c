/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** square
*/

#include "../../include/prototype.h"

void put_square(canvas_t *canvas, sfVector2f pos, int size, sfColor color)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int index = GET_INDEX((pos.x -size / 2), (pos.y -size / 2), i, j);
            add_pixel(canvas, index, color);
        }
    }
}
