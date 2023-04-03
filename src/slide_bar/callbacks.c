/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** callbacks
*/

#include "../../include/prototype.h"

void slider_pressed(slide_bar_t *slide_bar, sfMouseButtonEvent mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(
            slide_bar->slider->rect);
    if (sfFloatRect_contains(&bounds, (float)mouse.x, (float)mouse.y))
        slide_bar->slider->state = PRESSED;
    else
        slide_bar->slider->state = NONE;
}

void slider_released(slide_bar_t *slide_bar, sfMouseButtonEvent mouse)
{
    slide_bar->slider->state = NONE;
}

static int normalize_pos(float max_x, float min_x, float x)
{
    if (x < min_x)
        return ((int)min_x);
    if (x > max_x)
        return ((int)max_x);
    return ((int)x);
}

static void update_slider_pos(slide_bar_t *slider_bar, float pos_x)
{
    slider_t *slider = slider_bar->slider;
    int x = normalize_pos(slider->max_pos.x, slider->min_pos.x, pos_x);
    if (pos_x > slider->min_pos.x && pos_x < slider->max_pos.x) {
        slider->position = (sfVector2f) {(pos_x - (slider->size.x / 2)),
            slider->position.y};
        sfRectangleShape_setPosition(slider->rect, slider->position);
        slider_bar->value = ((x - (int)slider->min_pos.x) * 100)
            / ((int)slider->max_pos.x - (int)slider->min_pos.x);
    }
}

void slider_move(slide_bar_t *slide_bar, sfMouseMoveEvent mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(
            slide_bar->slider->rect);
    if (sfFloatRect_contains(&bounds, (float)mouse.x, (float)mouse.y)
        && IS_PRESSED(slide_bar->slider->state))
        update_slider_pos(slide_bar, (float)mouse.x);
    else
        slide_bar->slider->state = NONE;
}
