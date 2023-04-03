/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** create_rectangle.c
*/

#include "../../include/prototype.h"

int free_rectangle(rectangle_t *rectangle)
{
    sfRectangleShape_destroy(rectangle->rectangle);
    sfTexture_destroy(rectangle->texture);
    free(rectangle);
    return 0;
}

rectangle_t *create_rectangle(sfVector2f size, sfVector2f position)
{
    rectangle_t *rectangle = malloc(sizeof(rectangle_t));
    rectangle->texture = sfTexture_create(size.x, size.y);
    rectangle->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(rectangle->rectangle, size);
    sfRectangleShape_setPosition(rectangle->rectangle, position);
    sfRectangleShape_setTexture(rectangle->rectangle,
        rectangle->texture, sfFalse);
    return rectangle;
}
