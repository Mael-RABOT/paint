/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** init_ruban.c
*/

#include "../../include/prototype.h"

static int init_edition(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->edition = create_object((sfVector2f){81, 0},
        (sfVector2f)MENU_SIZE, EDITION_PATH, &do_nothing);
    ui->edition->swap = 0;
    append_object(ui->edition, SQUARE_S, &brush_normal);
    append_object(ui->edition, RECTANGLE_S, &brush_rectangle);
    append_object(ui->edition, CIRCLE_S, &brush_circle);
    return 0;
}

static int init_about(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->about = create_object((sfVector2f){162, 0},
        (sfVector2f)MENU_SIZE, ABOUT_PATH, &about);
    ui->about->swap = 0;
    return 0;
}

static int init_file(app_t *app)
{
    ui_button_t *ui = app->ui_button;
    ui->file = create_object((sfVector2f){0, 0},
        (sfVector2f)MENU_SIZE, FILE_PATH, &do_nothing);
    ui->file->swap = 0;
    append_object(ui->file, SAVE_PATH, &b_save_image);
    append_object(ui->file, SAVE_AS_PATH, &b_save_as_image);
    append_object(ui->file, LOAD_PATH, &b_load_image);
    return 0;
}

int init_ruban(app_t *app)
{
    init_file(app);
    init_edition(app);
    init_about(app);
    return 0;
}
