/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** init_slide_bar
*/

#include "../../include/prototype.h"

static sfSprite *slide_bar_foreground(sfIntRect rect, sfVector2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(SLIDER_FOREGROUND, &rect);
    sfSprite *foreground = sfSprite_create();
    sfSprite_setTexture(foreground, texture, sfFalse);
    sfSprite_setPosition(foreground, pos);
    return (foreground);
}

static slider_t *init_slider(sfVector2f pos, sfVector2f slide_bar_size)
{
    slider_t *slider = malloc(sizeof(slider_t));
    slider->rect = sfRectangleShape_create();
    slider->size = (sfVector2f)SLIDER_SIZE;
    sfRectangleShape_setSize(slider->rect, (sfVector2f)SLIDER_SIZE);
    sfRectangleShape_setPosition(slider->rect, pos);
    sfTexture *head = sfTexture_createFromFile(SLIDER_HEAD, sfFalse);
    sfRectangleShape_setTexture(slider->rect, head, sfFalse);
    slider->position = pos;
    slider->min_pos = (sfVector2f){pos.x + SLIDER_OFFSET, pos.y};
    slider->max_pos = (sfVector2f){
        slide_bar_size.x + pos.x - (SLIDER_OFFSET + 3),
        slide_bar_size.y + pos.y};
    slider->state = NONE;
    return (slider);
}

slide_bar_t *init_slide_bar(sfVector2f pos)
{
    slide_bar_t *slide_bar = malloc(sizeof(slide_bar_t));
    slide_bar->position = pos;
    slide_bar->size = (sfVector2f)SLIDE_BAR_SIZE;
    slide_bar->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(slide_bar->rect, slide_bar->size);
    sfRectangleShape_setPosition(slide_bar->rect, pos);
    sfTexture *backg = sfTexture_createFromFile(SLIDER_BACKGROUND, sfFalse);
    sfRectangleShape_setTexture(slide_bar->rect, backg, sfFalse);
    slide_bar->show_off = (sfIntRect){0, 0, 0, (int)slide_bar->size.y};
    slide_bar->fill_up = slide_bar_foreground(slide_bar->show_off, pos);
    slide_bar->value = 0;
    slide_bar->slider = init_slider(pos, slide_bar->size);
    slide_bar->pressed = &slider_pressed;
    slide_bar->released = &slider_released;
    slide_bar->move = &slider_move;
    return (slide_bar);
}
