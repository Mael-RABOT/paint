/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** my_struct
*/

#ifndef MY_STRUCT
    #define MY_STRUCT

    #include "prototype.h"

    typedef struct app app_t;

    typedef struct button {
        sfRectangleShape *rect;
        int (*is_clicked) (struct button *, sfMouseButtonEvent *);
        int (*is_released) (struct button *, sfMouseButtonEvent *);
        int (*is_hover) (struct button *, sfMouseMoveEvent *);
        void (*action) (struct app *, int);
        state_t state;
        sfIntRect texture_rect;
        sfTexture *texture;
        bool_t pressed;
    } button_t;

    typedef struct object {
        button_t *button;
        int swap;
        int status;
        struct object *next;
        struct object *past;
    } object_t;

    typedef struct brush {
        int type;
        size_t size;
        sfVector2u rect_size;
        sfColor color;
        sfColor old_color;
        brush_mode_t mode;
        brush_shape_t shape;
    } brush_t;

    typedef struct sprite {
        sfSprite *sprite;
        sfTexture *texture;
    } sprite_t;

    typedef struct rectangle {
        sfTexture *texture;
        sfRectangleShape *rectangle;
    } rectangle_t;

    typedef struct circle_info {
        int radius;
        int size;
        int i;
        int j;
    } circle_info_t;

    typedef struct welcome_menu {
        button_t *button;
        sfSprite *background;
        sfTexture *texture_background;
    } welcome_menu_t;

    typedef struct layer {
        sfUint8 *layer;
        rectangle_t *rectangle;
        struct layer *next_layer;
    } layer_t;

    typedef struct canvas {
        layer_t *layer;
        layer_t *selected_layer;
        sfTexture *foreground_texture;
        sfSprite *foreground;
        sfColor next_background;
        sfColor background;
        sfVector2u mouse_pos;
    } canvas_t;

    typedef struct slider {
        sfVector2f position;
        sfVector2f size;
        sfVector2f min_pos;
        sfVector2f max_pos;
        sfRectangleShape *rect;
        state_t state;
    } slider_t;

    typedef struct slide_bar {
        sfVector2f position;
        sfVector2f size;
        sfRectangleShape *rect;
        sfIntRect show_off;
        sfSprite *fill_up;
        slider_t *slider;
        void (*pressed) (struct slide_bar *, sfMouseButtonEvent);
        void (*released) (struct slide_bar *, sfMouseButtonEvent);
        void (*move) (struct slide_bar *, sfMouseMoveEvent);
        int value;
    } slide_bar_t;

    typedef struct ui_button {
        object_t *file;
        object_t *edition;
        object_t *about;
        object_t *color;
        object_t *bg_color;
        object_t *size_button;
        object_t *pencil;
        object_t *eraser;
        object_t *brush;
        object_t *layer_preview;
        object_t *add;
        object_t *sub;
        object_t *up;
        object_t *down;
    } ui_button_t;

    typedef struct keyboard {
        sfRenderWindow *window;
        sfText *text;
        sfFont *font;
        int shift;
        char *input;
    } keyboard_t;

    typedef enum filetype {
        png = 0,
        jpg,
        bpm
    } filetype_t;

    typedef struct app {
        ui_button_t *ui_button;
        sfRenderWindow *window;
        welcome_menu_t *welcome_menu;
        canvas_t *canvas;
        brush_t *brush;
        char *save_path;
        int is_save;
        char *load_path;
        int is_focus;
        filetype_t filetype;
        bool_t overwrite;
    } app_t;

#endif //MY_STRUCT
