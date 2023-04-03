/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** free_object.c
*/

#include "../../include/prototype.h"

int free_button(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    sfTexture_destroy(button->texture);
    free(button);
    return 0;
}

int free_one_object(object_t *object, int index)
{
    int i = 0;
    while (i < index) {
        object = object->next;
        i += 1;
    }
    free(object->next->button);
    object->next = object->next->next;
    free(object->next);
    return 0;
}

int free_object(object_t *object)
{
    if (object == NULL) {
        return 0;
    } else {
        object_t *tmp_object = object->next;
        free_button(object->button);
        free(object);
        return free_object(tmp_object);
    }
}
