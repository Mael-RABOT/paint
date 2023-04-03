/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** drawing_functions
*/

#include "../../include/prototype.h"

void pen_down(app_t *app, sfMouseButtonEvent mouse)
{
    int x = (int)mouse.x - (int)DRAWING_POS_X;
    int y = (int)mouse.y - (int)DRAWING_POS_Y;
    if (x > 0 && x < DRAWING_WIDTH && y > 0 && y < DRAWING_HEIGHT) {
        app->brush->mode = DOWN;
        draw_selector(app, (sfVector2f){(float)x, (float)y});
        sfTexture_updateFromPixels(app->canvas->selected_layer->rectangle->
            texture, app->canvas->selected_layer->layer, DRAWING_WIDTH,
            DRAWING_HEIGHT, 0, 0);
        app->canvas->mouse_pos = (sfVector2u){x, y};
    }
}

void pen_up(app_t *app, sfMouseButtonEvent mouse)
{
    int x = (int)mouse.x - (int)DRAWING_POS_X;
    int y = (int)mouse.y - (int)DRAWING_POS_Y;
    if (x > 0 && x < DRAWING_WIDTH && y > 0 && y < DRAWING_HEIGHT)
        app->brush->mode = UP;
}

void draw(app_t *app, sfMouseMoveEvent mouse)
{
    int x = (int)mouse.x - (int)DRAWING_POS_X;
    int y = (int)mouse.y - (int)DRAWING_POS_Y;
    if (x > 0 && x < DRAWING_WIDTH && y > 0 && y < DRAWING_HEIGHT
        && app->brush->mode == DOWN) {
        draw_selector(app, (sfVector2f){(float)x, (float)y});
        sfTexture_updateFromPixels(app->canvas->selected_layer->rectangle->
            texture, app->canvas->selected_layer->layer, DRAWING_WIDTH,
            DRAWING_HEIGHT, 0, 0);
        app->canvas->mouse_pos = (sfVector2u){x, y};
    }
}
