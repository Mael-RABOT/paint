/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** button_event.c
*/

#include "../../include/prototype.h"

static int pre_detect_hover(object_t *object)
{
    int i = 0;
    object_t *tmp_object = object;
    while (tmp_object != NULL) {
        if (tmp_object->button->state == HOVER)
            return i;
        i += 1;
        tmp_object = tmp_object->next;
    }
    return -1;
}

int detect_button(button_t *button, sfEvent event)
{
    button->state = NONE;
    if (event.type == sfEvtMouseMoved)
        button->is_hover(button, &event.mouseMove);
    if (event.type == sfEvtMouseButtonPressed)
        button->is_clicked(button, &event.mouseButton);
    if (event.type == sfEvtMouseButtonReleased)
        button->is_released(button, &event.mouseButton);
    sfRectangleShape_setOutlineThickness(button->rect, 0);
    return 0;
}

static int recursive_detection(object_t *object, sfEvent event)
{
    if (object == NULL)
        return 0;
    detect_button(object->button, event);
    return recursive_detection(object->next, event);
}

static int execute_action(app_t *app, object_t **object)
{
    object_t *tmp_object = *object;
    while (tmp_object != NULL) {
        if (tmp_object->button->state == PRESSED) {
            tmp_object->button->action(app, tmp_object->status);
            tmp_object->button->state = NONE;
            swap_button(object, tmp_object);
            break;
        }
        tmp_object = tmp_object->next;
    }
    return 0;
}

int button_event(app_t *app, object_t **object, sfEvent event)
{
    int status = pre_detect_hover(*object);
    if (status >= 0) {
        recursive_detection(*object, event);
    }
    if (status == -1 && event.type == sfEvtMouseMoved)
        (*object)->button->is_hover((*object)->button, &event.mouseMove);
    execute_action(app, object);
    object_t *tmp_object = (*object);
    while (tmp_object != NULL) {
        update_texture(tmp_object->button);
        tmp_object = tmp_object->next;
    }
    return 0;
}
