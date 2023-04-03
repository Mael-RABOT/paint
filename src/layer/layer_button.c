/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** layer_button.c
*/

#include "../../include/prototype.h"

int create_preview_button(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->layer_preview = create_object((sfVector2f){54, 543},
        (sfVector2f)MENU_SIZE, ADD_PATH, &do_nothing);
    ui->bg_color->swap = 0;
    sfRectangleShape_setTexture(ui->layer_preview->button->rect,
        app->canvas->layer->rectangle->texture, sfTrue);
    return 0;

}

int create_layer_button(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->add = create_object((sfVector2f){54, 699},
        (sfVector2f)MENU_SIZE, ADD_PATH, &add_layer);
    ui->sub = create_object((sfVector2f){54, 729},
        (sfVector2f)MENU_SIZE, SUB_PATH, &delete_layer);
    ui->bg_color->swap = 1;
    return 0;
}
