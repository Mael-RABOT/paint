/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** init_ui_button.c
*/

#include "../../include/prototype.h"

static int alloc_brush(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->brush = create_object((sfVector2f){54, 387},
        (sfVector2f)MENU_SIZE, SQUARE_S, &brush_normal);
    ui->brush->swap = 1;
    append_object(ui->brush, RECTANGLE_S, &brush_rectangle);
    append_object(ui->brush, CIRCLE_S, &brush_circle);
    return 0;
}

static int alloc_button(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->size_button = create_object((sfVector2f)SIZE_BUTTON_POS,
        (sfVector2f)MENU_SIZE, SIZE_BUTTON_TEXTURE,
        &size_button_action);
    ui->pencil = create_object((sfVector2f)PENCIL_POS,
        (sfVector2f)MENU_SIZE, PENCIL_TEXTURE, &pencil_action);
    ui->eraser = create_object((sfVector2f)ERASER_POS,
        (sfVector2f)MENU_SIZE, ERASER_TEXTURE, &eraser_action);
    return 0;
}

static int alloc_bgcolor(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->bg_color = create_object((sfVector2f){1769, 37},
        (sfVector2f)MENU_SIZE, WHITE, &b_alloc_color_bg);
    ui->bg_color->swap = 1;
    append_object(ui->bg_color, BLACK, &b_alloc_color_bg);
    append_object(ui->bg_color, RED, &b_alloc_color_bg);
    append_object(ui->bg_color, GREEN, &b_alloc_color_bg);
    append_object(ui->bg_color, BLUE, &b_alloc_color_bg);
    append_object(ui->bg_color, YELLOW, &b_alloc_color_bg);
    append_object(ui->bg_color, MAGENTA, &b_alloc_color_bg);
    append_object(ui->bg_color, CYAN, &b_alloc_color_bg);
    return 0;
}

static int alloc_color(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->color = create_object((sfVector2f){443, 37},
        (sfVector2f)MENU_SIZE, BLACK, &b_alloc_color);
    ui->color->swap = 1;
    append_object(ui->color, WHITE, &b_alloc_color);
    append_object(ui->color, RED, &b_alloc_color);
    append_object(ui->color, GREEN, &b_alloc_color);
    append_object(ui->color, BLUE, &b_alloc_color);
    append_object(ui->color, YELLOW, &b_alloc_color);
    append_object(ui->color, MAGENTA, &b_alloc_color);
    append_object(ui->color, CYAN, &b_alloc_color);
    append_object(ui->color, "./assets/color/custom.png", &custom_color);
    return 0;
}

int init_ui_button(app_t *app)
{
    app->ui_button = malloc(sizeof(ui_button_t));
    if (app->ui_button == NULL)
        return 84;
    alloc_color(app);
    alloc_bgcolor(app);
    alloc_button(app);
    alloc_brush(app);
    init_ruban(app);
    create_layer_button(app);
    create_preview_button(app);
    return 0;
}
