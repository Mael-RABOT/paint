/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** welcome_screen
*/

#include "../../include/prototype.h"

static int event_manager(sfRenderWindow *window, button_t *button)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : "";
        detect_button(button, event);
    }
    return (0);
}

void play_squish(void)
{
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(SLIME);
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buff);
    sfSound_setVolume(sound, 40);
    sfSound_play(sound);
}

int welcome_screen(app_t *app)
{
    int ctrl = 0;
    bool_t welcome = TRUE;
    while (sfRenderWindow_isOpen(app->window) && welcome) {
        sfRenderWindow_clear(app->window, sfWhite);
        ctrl = (IS_NORMAL(app->welcome_menu->button->state)
        || IS_HOVER(app->welcome_menu->button->state)) ? 1 : 0;
        event_manager(app->window, app->welcome_menu->button);
        if (IS_PRESSED(app->welcome_menu->button->state) && ctrl)
            play_squish();
        update_texture(app->welcome_menu->button);
        sfRenderWindow_drawSprite(app->window,
            app->welcome_menu->background, NULL);
        sfRenderWindow_drawRectangleShape(app->window,
            app->welcome_menu->button->rect, NULL);
        sfRenderWindow_display(app->window);
        if (IS_RELEASED(app->welcome_menu->button->state))
            welcome = FALSE;
    }
    return EXIT_SUCCESS;
}
