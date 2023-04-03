/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** display.c
*/

#include "../include/prototype.h"

static int display_all_menu(sfRenderWindow *window, object_t *object)
{
    object_t *tmp_object = object;
    while (tmp_object != NULL) {
        sf_DRS(window, tmp_object->button->rect, NULL);
        tmp_object = tmp_object->next;
    }
    return 0;
}

static int menu_hover_state(object_t *object)
{
    object_t *tmp_object = object;
    while (tmp_object != NULL) {
        if (tmp_object->button->state == HOVER)
            return 1;
        tmp_object = tmp_object->next;
    }
    return 0;
}

int display_menu(sfRenderWindow *window, object_t *object)
{
    sf_DRS(window, object->button->rect, NULL);
    if (menu_hover_state(object) == 1) {
        display_all_menu(window, object);
    }
    return 0;
}
