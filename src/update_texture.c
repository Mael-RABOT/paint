/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** update_texture.c
*/

#include "../include/prototype.h"

int update_texture(button_t *button)
{
    sfIntRect new_rect = button->texture_rect;
    size_t offset_x = new_rect.width;
    if (IS_HOVER(button->state))
        new_rect.left = offset_x;
    if (IS_PRESSED(button->state))
        new_rect.left = offset_x * 2;
    if (IS_NORMAL(button->state))
        new_rect.left = 0;
    if (IS_RELEASED(button->state))
        new_rect.left = 0;
    sfRectangleShape_setTextureRect(button->rect, new_rect);
    return 0;
}
