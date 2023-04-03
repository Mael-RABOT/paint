/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** swap_button.c
*/

#include "../../include/prototype.h"

object_t *swap_button(object_t **object, object_t *tmp_object)
{
    if (tmp_object->swap == 0)
        return 0;
    if (tmp_object == *object)
        return NULL;
    sfVector2f position_1 = sfRectangleShape_getPosition
        (tmp_object->button->rect);
    sfVector2f position_2 = sfRectangleShape_getPosition
        ((*object)->button->rect);
    sfRectangleShape_setPosition(tmp_object->button->rect, position_2);
    sfRectangleShape_setPosition((*object)->button->rect, position_1);
    tmp_object->past->next = tmp_object->next;
    if (tmp_object->next != NULL)
        tmp_object->next->past = tmp_object->past;
    tmp_object->next = *object;
    tmp_object->past = NULL;
    (*object)->past = tmp_object;
    *object = tmp_object;
    return 0;
}
