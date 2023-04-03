/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** about.c
*/

#include "../../include/prototype.h"

typedef struct about {
    sfRenderWindow *window;
    sfFont *font;
    sfText *text;
    char *string;
} about_t;

static about_t *create_about_window(void)
{
    about_t *about = malloc(sizeof(about_t));
    sfVideoMode videomode = {500, 300, 32};
    about->window = sfRenderWindow_create(videomode, "About Us",
        sfResize | sfClose, NULL);
    about->text = sfText_create();
    about->font = sfFont_createFromFile(FONT);
    about->string = my_strdup("mael.rabot@epitech.eu\n"
        "mathieu.borel@epitech.eu");
    sfText_setFont(about->text, about->font);
    sfText_setString(about->text, about->string);
    sfText_setColor(about->text, sfBlack);
    return about;
}

static void free_about_window(about_t *about)
{
    sfText_destroy(about->text);
    sfFont_destroy(about->font);
    sfRenderWindow_destroy(about->window);
    free(about->string);
    free(about);
}

static void event_manager(about_t *about)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(about->window, &event)) {
        (event.type == sfEvtClosed) ? sfRenderWindow_close(about->window) : 0 ;
    }
}

void about(app_t *app, int status)
{
    about_t *about = create_about_window();
    while (sfRenderWindow_isOpen(about->window)) {
        sfRenderWindow_clear(about->window, sfWhite);
        event_manager(about);
        sfRenderWindow_drawText(about->window, about->text, NULL);
        sfRenderWindow_display(about->window);
    }
    free_about_window(about);

}
