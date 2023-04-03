/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** tips
*/

#include "../../include/prototype.h"

static char *get_tips(void)
{
    char *line = NULL;
    size_t len;
    FILE *stream = fopen(TIPS_FILE, "r");
    if (stream == NULL)
        return ("ERROR");
    int number = rand() % TIPS_NUMBER + 1;
    char *res;
    int i = 0;
    while (getline(&line, &len, stream) != -1) {
        i += 1;
        if (i == number) {
            res = malloc(sizeof(char) * (my_strlen(line) + 1));
            my_strcpy(res, line);
        }
    }
    free(line);
    fclose(stream);
    return (res);
}

static void tips_event(sfRenderWindow *tips)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(tips, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(tips);
    }
}

void tips_screen(void)
{
    sfText *text = sfText_create();
    sfFont *my_font = sfFont_createFromFile(FONT);
    sfText_setFont(text, my_font);
    sfText_setStyle(text, sfTextRegular);
    sfText_setCharacterSize(text, 20);
    char *tips_string = get_tips();
    sfText_setString(text, tips_string);
    sfRenderWindow *tips = sfRenderWindow_create(
        (sfVideoMode){TIPS_WIDTH, TIPS_HEIGHT, 32},
        TIPS_TITLE, sfClose, NULL);
    while (sfRenderWindow_isOpen(tips)) {
        tips_event(tips);
        sfRenderWindow_drawText(tips, text, NULL);
        sfRenderWindow_display(tips);
    }
    free(tips_string);
    sfFont_destroy(my_font);
    sfText_destroy(text);
    sfRenderWindow_destroy(tips);
}
