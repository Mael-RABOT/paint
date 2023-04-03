/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** keyboard_input.c
*/

#include "../../include/prototype.h"

static int detect_key(keyboard_t *keyboard, sfEvent event)
{
    if (event.key.code == sfKeyBack) {
        keyboard->input[my_strlen(keyboard->input) - 1] = '\0';
        return 0;
    } else if (event.key.code == sfKeyLShift) {
        keyboard->shift = 1;
        return 0;
    }
    if (keyboard->shift == 1) {
        if (event.key.code == 48) {
            my_strappend(keyboard->input, '.');
            return 0;
        }
        if (event.key.code == 52) {
            my_strappend(keyboard->input, '/');
            return 0;
        }
        my_strappend(keyboard->input, event.key.code + 65);
    } else
        my_strappend(keyboard->input, event.key.code + 97);
    return 0;
}

static int event(keyboard_t *keyboard)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(keyboard->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(keyboard->window);
        if (event.type == sfEvtKeyPressed) {
            detect_key(keyboard, event);
            sfText_setString(keyboard->text, keyboard->input);
        }
    }
    return 0;
}

static keyboard_t *init_window(void)
{
    keyboard_t *keyboard = malloc(sizeof(keyboard_t));
    sfVideoMode videomode = {500, 100, 32};
    keyboard->window = sfRenderWindow_create(
        videomode, "input", sfResize | sfClose, NULL);
    keyboard->font = sfFont_createFromFile(FONT);
    keyboard->text = sfText_create();
    sfText_setFont(keyboard->text, keyboard->font);
    sfText_setStyle(keyboard->text, sfTextRegular);
    sfText_setCharacterSize(keyboard->text, 20);
    keyboard->input = malloc(512);
    keyboard->input[0] = '\0';
    return keyboard;
}

char *keyboard_input(void)
{
    keyboard_t *keyboard = init_window();
    while (sfRenderWindow_isOpen(keyboard->window)) {
        sfRenderWindow_clear(keyboard->window, sfBlack);
        event(keyboard);
        sfRenderWindow_drawText(keyboard->window, keyboard->text, NULL);
        sfRenderWindow_display(keyboard->window);
    }
    sfRenderWindow_destroy(keyboard->window);
    sfText_destroy(keyboard->text);
    sfFont_destroy(keyboard->font);
    char *string = keyboard->input;
    free(keyboard);
    return string;
}
