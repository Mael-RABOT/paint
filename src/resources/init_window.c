/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** init_window.c
*/

#include "../../include/prototype.h"

static int init_window(app_t *app)
{
    sfVideoMode videomode =
            {STD_WINDOW_WIDTH, STD_WINDOW_HEIGHT, STD_WINDOW_BPP};
    app->window = sfRenderWindow_create
            (videomode, TITLE, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(app->window, 60);
    if (app->window == NULL)
        return 84;
    return 0;
}

static int init_welcome(app_t *app)
{
    app->welcome_menu = malloc(sizeof(welcome_menu_t));
    if (app->welcome_menu == NULL)
        return 84;
    app->welcome_menu->button = create_button((sfVector2f){STD_WINDOW_WIDTH
        / 1.6, (float)STD_WINDOW_HEIGHT / 3}, (sfVector2f){300, 150},
        WELCOME_BUTTON, NULL);
    app->welcome_menu->background = sfSprite_create();
    app->welcome_menu->texture_background = sfTexture_createFromFile(
    WELCOME_BACKGROUND, NULL);
    sfSprite_setTexture(app->welcome_menu->background,
        app->welcome_menu->texture_background, sfFalse);
    return 0;
}

canvas_t *init_canvas(sfColor color)
{
    canvas_t *canvas = malloc(sizeof(canvas_t));
    canvas->layer = create_layer(sfWhite);
    set_background_color(canvas->layer->layer, color);
    canvas->selected_layer = canvas->layer;
    canvas->background = color;
    canvas->foreground_texture = sfTexture_createFromFile(FOREGROUND, NULL);
    canvas->foreground = sfSprite_create();
    sfSprite_setTexture(canvas->foreground,
        canvas->foreground_texture, sfFalse);
    canvas->mouse_pos = (sfVector2u){0, 0};
    return (canvas);
}

brush_t *init_brush(void)
{
    brush_t *brush = malloc(sizeof(brush_t));
    brush->size = STD_BRUSH_SIZE;
    brush->rect_size = (sfVector2u)STD_BRUSH_RECT_SIZE;
    brush->color = STD_BRUSH_COLOR;
    brush->old_color = STD_BRUSH_COLOR;
    brush->type = PENCIL;
    brush->mode = UP;
    brush->shape = STD_TOOL;
    return (brush);
}

app_t *init_app(sfColor color)
{
    app_t *app = malloc(sizeof(app_t));
    if (app == NULL)
        return NULL;
    if (init_window(app) == 84)
        return NULL;
    if (init_welcome(app) == 84)
        return NULL;
    app->canvas = init_canvas(color);
    if (init_ui_button(app) == 84)
        return NULL;
    app->brush = init_brush();
    app->save_path = NULL;
    app->load_path = NULL;
    app->is_focus = 1;
    app->filetype = png;
    return app;
}
