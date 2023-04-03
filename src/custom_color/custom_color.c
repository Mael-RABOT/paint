/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** custom_color
*/

#include "../../include/prototype.h"

void custom_event(sfRenderWindow *custom, slide_bar_t **array)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(custom, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(custom);
        slide_bar_event(event, array);
    }
}

void custom_display(sfRenderWindow *custom, slide_bar_t **array)
{
    for (int i = 0; array[i] != NULL; i++)
        display_slide_bar(custom, array[i]);
}

void custom_color(app_t *app, int status)
{
    app->is_focus = 0;
    sfRenderWindow *custom = sfRenderWindow_create((sfVideoMode){350, 200, 32},
        CUSTOM_TITLE, sfClose, NULL);
    sprite_t *background = create_sprite(CUSTOM_BACKGROUND);
    slide_bar_t **array = init_slide_bar_array();
    while (sfRenderWindow_isOpen(custom)) {
        sfRenderWindow_clear(custom, sfBlack);
        sfRenderWindow_drawSprite(custom, background->sprite, NULL);
        custom_event(custom, array);
        custom_display(custom, array);
        update_color(app->brush, array);
        sfRenderWindow_display(custom);
    }
    free_sprite(background);
    sfRenderWindow_destroy(custom);
    app->is_focus = 1;
}
