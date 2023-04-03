/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** brush_size_windows
*/

#include "../../include/prototype.h"

static sfRenderWindow *init_size_window(char *title, sfVector2f size)
{
    sfRenderWindow *window = sfRenderWindow_create(
        (sfVideoMode){size.x, size.y, 32},
        title, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

static void size_bar_display(sfRenderWindow *window, slide_bar_t **array)
{
    for (int i = 0; array[i] != NULL; i++)
        display_slide_bar(window, array[i]);
}

static void square_size(app_t *app)
{
    sfRenderWindow *window = init_size_window(SQUARE_TITLE,
        (sfVector2f)SQUARE_WINDOW);
    slide_bar_t **array = size_slider(SQUARE);
    if (array == NULL)
        return;
    sprite_t *background = create_sprite(SQUARE_BG);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        size_event(window, array);
        sfRenderWindow_drawSprite(window, background->sprite, NULL);
        size_bar_display(window, array);
        sfRenderWindow_display(window);
    }
    update_brush(app, SQUARE, array);
    sfRenderWindow_destroy(window);
    free_sprite(background);
    free_slide_bar_array(array);
}

static void rectangle_size(app_t *app)
{
    sfRenderWindow *window = init_size_window(SQUARE_TITLE,
            (sfVector2f)RECTANGLE_WINDOW);
    slide_bar_t **array = size_slider(RECTANGLE);
    if (array == NULL)
        return;
    sprite_t *background = create_sprite(RECTANGLE_BG);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        size_event(window, array);
        sfRenderWindow_drawSprite(window, background->sprite, NULL);
        size_bar_display(window, array);
        sfRenderWindow_display(window);
    }
    update_brush(app, RECTANGLE, array);
    sfRenderWindow_destroy(window);
    free_sprite(background);
    free_slide_bar_array(array);
}

void update_size(app_t *app)
{
    switch (app->brush->shape) {
        case SQUARE:
            square_size(app);
            break;
        case CIRCLE:
            square_size(app);
            break;
        case RECTANGLE:
            rectangle_size(app);
            break;
    }
}
