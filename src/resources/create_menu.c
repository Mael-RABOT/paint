/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** create_menu.c
*/

#include "../../include/prototype.h"

object_t *create_object(sfVector2f position, sfVector2f size,
    char *pathfile, void (*action)(app_t *app, int))
{
    object_t *object = malloc(sizeof(object_t));
    if (object == NULL)
        return NULL;
    object->button = create_button(position, size, pathfile, action);
    object->status = 0;
    object->swap = 0;
    object->next = NULL;
    object->past = NULL;
    return object;
}

int append_object(object_t *object, char *pathfile,
    void (*action)(app_t *app, int))
{
    int status = 1;
    object_t *tmp_object = object;
    while (tmp_object->next != NULL) {
        tmp_object = tmp_object->next;
        status += 1;
    }
    sfVector2f size = sfRectangleShape_getSize(tmp_object->button->rect);
    sfRectangleShape *rect = tmp_object->button->rect;
    sfVector2f position = sfRectangleShape_getPosition(rect);
    position.y += size.y;
    tmp_object->next = create_object(position, size, pathfile, action);
    tmp_object->next->status = status;
    tmp_object->next->past = tmp_object;
    tmp_object->next->swap = tmp_object->swap;
    tmp_object->next->next = NULL;
    return 0;
}
