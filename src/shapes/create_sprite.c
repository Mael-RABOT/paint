/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** init_sprite.c
*/

#include "../../include/prototype.h"

int free_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite);
    return 0;
}

sprite_t *create_sprite(char *pathfile)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(pathfile, NULL);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    return sprite;
}
