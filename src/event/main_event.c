/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** main_event.c
*/

#include "../../include/prototype.h"

static int call_button_event(app_t *app, sfEvent event)
{
    button_event(app, &app->ui_button->file, event);
    button_event(app, &app->ui_button->edition, event);
    button_event(app, &app->ui_button->about, event);
    button_event(app, &app->ui_button->color, event);
    button_event(app, &app->ui_button->bg_color, event);
    button_event(app, &app->ui_button->size_button, event);
    button_event(app, &app->ui_button->pencil, event);
    button_event(app, &app->ui_button->eraser, event);
    button_event(app, &app->ui_button->brush, event);
    button_event(app, &app->ui_button->add, event);
    button_event(app, &app->ui_button->sub, event);
    button_event(app, &app->ui_button->layer_preview, event);

    return 0;
}

int main_event(app_t *app)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(app->window, &event)) {
        (event.type == sfEvtClosed) ? sfRenderWindow_close(app->window) : 0 ;
        if (event.type == sfEvtMouseButtonPressed)
            mousse_button_pressed(app, event.mouseButton);
        if (event.type == sfEvtMouseButtonReleased)
            mousse_button_released(app, event.mouseButton);
        if (event.type == sfEvtMouseMoved)
            mousse_move(app, event.mouseMove);
        if (event.type == sfEvtKeyPressed)
            key_pressed(app, event.key);
        call_button_event(app, event);
    }
    return 0;
}
