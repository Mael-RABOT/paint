/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** paint.c
*/

#include "../include/prototype.h"

void display_layer(sfRenderWindow *window, layer_t *layer)
{
    if (layer == NULL)
        return;
    sf_DRS(window, layer->rectangle->rectangle, NULL);
    display_layer(window, layer->next_layer);
}

static int display_button(app_t *app)
{
    display_menu(app->window, app->ui_button->file);
    display_menu(app->window, app->ui_button->edition);
    display_menu(app->window, app->ui_button->about);
    display_menu(app->window, app->ui_button->size_button);
    display_menu(app->window, app->ui_button->pencil);
    display_menu(app->window, app->ui_button->eraser);
    display_menu(app->window, app->ui_button->color);
    display_menu(app->window, app->ui_button->bg_color);
    display_menu(app->window, app->ui_button->brush);
    display_menu(app->window, app->ui_button->layer_preview);
    display_menu(app->window, app->ui_button->add);
    display_menu(app->window, app->ui_button->sub);
    return 0;
}

void display_elements(app_t *app)
{
    display_layer(app->window, app->canvas->layer);
    sfRenderWindow_drawSprite(app->window, app->canvas->foreground, NULL);
    display_button(app);
}

static int gloop(app_t *app, bool_t tips)
{
    int ctrl = (tips) ? 0 : 1;
    update_loaded_file(app);
    while (sfRenderWindow_isOpen(app->window)) {
        sfRenderWindow_clear(app->window, sfBlack);
        main_event(app);
        display_elements(app);
        sfRenderWindow_display(app->window);
        if (ctrl++ == 0)
            tips_screen();
    }
    return 0;
}

int paint(char *path, bool_t welcome, bool_t save, bool_t tips)
{
    app_t *app = init_app(STD_BACK_COLOR);
    if (app == NULL)
        return (EXIT_FAILURE);
    if (path != NULL)
        app->load_path = my_strdup(path);
    if (welcome)
        welcome_screen(app);
    if (path != NULL)
        load_image(app);
    gloop(app, tips);
    auto_save(app, save);
    free_window(app);
    return 0;
}
