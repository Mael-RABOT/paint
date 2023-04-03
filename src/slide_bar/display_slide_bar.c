/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** display
*/

#include "../../include/prototype.h"

void display_slide_bar(sfRenderWindow *window, slide_bar_t *slide_bar)
{
    sfRenderWindow_drawRectangleShape(window, slide_bar->rect, NULL);
    sfSprite_setTextureRect(slide_bar->fill_up,
        (sfIntRect){(((int)slide_bar->size.x - SLIDER_OFFSET)
        - ((int)slide_bar->size.x - SLIDER_OFFSET) * slide_bar->value / 100),
        0, (int)slide_bar->size.x, 30});
    sfRenderWindow_drawSprite(window, slide_bar->fill_up, NULL);
    sfRenderWindow_drawRectangleShape(window, slide_bar->slider->rect, NULL);
}
