/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** rectangle
*/

#include "../../include/prototype.h"

void put_rectangle(canvas_t *canvas, sfVector2f pos, sfVector2u size,
    sfColor color)
{
    for (int i = 0; i < size.x; i++) {
        for (int j = 0; j < size.y; j++) {
            int index = GET_INDEX((pos.x - size.x / 2),
            (pos.y - size.y / 2), i, j);
            add_pixel(canvas, index, color);
        }
    }
}
