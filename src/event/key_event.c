/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** key_event
*/

#include "../../include/prototype.h"

static void key_size_update(app_t *app, sfKeyEvent mouse)
{
    if (mouse.code == 68) {
        if (mouse.shift)
            app->brush->size = STD_BRUSH_SIZE;
        else
            app->brush->size -= (app->brush->size > 2)
                ? ((app->brush->size > 100) ? 10 : 2) : 0;
    }
    if (mouse.code == sfKeyAdd) {
        if (mouse.shift)
            app->brush->size = MAX_BRUSH_SIZE;
        else
            app->brush->size += (app->brush->size < MAX_BRUSH_SIZE)
                ? ((app->brush->size >= 100) ? 10 : 2) : 0;
    }
}

static void key_default_update(app_t *app, sfKeyEvent mouse)
{
    if (mouse.code == sfKeyD && mouse.shift) {
            put_background(app->canvas, STD_BACK_COLOR);
            app->brush->color = STD_BRUSH_COLOR;
            app->brush->size = STD_BRUSH_SIZE;
        }
}

static void save_event(app_t *app, sfKeyEvent mouse)
{
    if (mouse.code && mouse.shift && mouse.code == sfKeyS) {
        app->overwrite = TRUE;
        save_image(app);
    } else if (mouse.code && mouse.code == sfKeyS) {
        app->overwrite = FALSE;
        save_image(app);
    }
    if (mouse.control && mouse.code == sfKeyO)
        load_image(app);
}

void key_pressed(app_t *app, sfKeyEvent mouse)
{
    if (mouse.code == sfKeyE) {
        app->brush->old_color = app->brush->color;
        app->brush->color = app->canvas->background;
    }
    if (mouse.code == sfKeyP)
        app->brush->color = app->brush->old_color;
    save_event(app, mouse);
    key_size_update(app, mouse);
    key_default_update(app, mouse);
    sfTexture_updateFromPixels(app->canvas->selected_layer->rectangle->
        texture, app->canvas->selected_layer->layer, DRAWING_WIDTH,
        DRAWING_HEIGHT, 0, 0);
}
