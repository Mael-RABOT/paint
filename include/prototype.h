/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** prototype
*/

#ifndef BASE_REPO_PROTOTYPE_H
    #define BASE_REPO_PROTOTYPE_H

    #include "enum.h"
    #include "my_lib.h"
    #include "include.h"
    #include "macros.h"

    //main file
    int paint(char *path, bool_t welcome_screen, bool_t save, bool_t tips);

    int parser(int ac, char **av);
    bool_t check_save(int ac, char **av);
    bool_t check_welcome(int ac, char **av);
    bool_t check_tips(int ac, char **av);

    int welcome_screen(app_t *app);
    app_t *init_app(sfColor color);
    int init_ui_button(app_t *app);
    int init_ruban(app_t *app);

    //tips
    void tips_screen(void);

    //custom color
    void custom_color(app_t *app, int status);
    slide_bar_t **init_slide_bar_array(void);
    void slide_bar_event(sfEvent event, slide_bar_t **array);
    void update_color(brush_t *brush, slide_bar_t **array);

    //brush size
    void update_size(app_t *app);
    slide_bar_t **size_slider(brush_shape_t shape);
    void free_slide_bar_array(slide_bar_t **array);
    void size_event(sfRenderWindow *window, slide_bar_t **array);
    void update_brush(app_t *app, brush_shape_t shape, slide_bar_t **array);
    void size_button_action(app_t *app, int status);

    int free_window(app_t *app);
    int free_object(object_t *object);
    int free_button(button_t *button);

    int display_menu(sfRenderWindow *window, object_t *object);

    char *keyboard_input(void);

    //events
    int main_event(app_t *app);
    int detect_button(button_t *button, sfEvent event);
    int button_event(app_t *app, object_t **object, sfEvent event);
    void key_pressed(app_t *app, sfKeyEvent mouse);
    void mousse_button_pressed(app_t *app, sfMouseButtonEvent mouse);
    void mousse_button_released(app_t *app, sfMouseButtonEvent mouse);
    void mousse_move(app_t *app, sfMouseMoveEvent mouse);

    //custom sprite struct
    sprite_t *create_sprite(char *pathfile);
    int free_sprite(sprite_t *sprite);

    rectangle_t *create_rectangle(sfVector2f size, sfVector2f position);
    int free_rectangle(rectangle_t *rectangle);

    //button object
    button_t *create_button(sfVector2f position, sfVector2f size,
        char *pathfile, void (*action)(app_t *app, int));
    int load_texture_button(button_t *button, char *, char *, char *);
    object_t *create_object(sfVector2f position, sfVector2f size,
        char *pathfile, void (*action)(app_t *app, int));
    int append_object(object_t *object, char *pathfile,
        void (*action)(app_t *app, int));
    object_t *swap_button(object_t **object, object_t *tmp_object);
    int update_texture(button_t *button);

    int free_one_object(object_t *object, int index);

    int is_clicked(button_t *button, sfMouseButtonEvent *mouse);
    int is_released(button_t *button, sfMouseButtonEvent *mouse);
    int is_hover(button_t *button, sfMouseMoveEvent *mouse);

    //drawing
    void draw_selector(app_t *app, sfVector2f pos);
    void put_square(canvas_t *canvas, sfVector2f pos, int size, sfColor color);
    void put_circle(canvas_t *canvas, sfVector2f pos, int size, sfColor color);
    void put_rectangle(canvas_t *canvas, sfVector2f pos, sfVector2u size,
        sfColor color);
    void add_pixel(canvas_t *canvas, int index, sfColor color);
    void set_background_color(sfUint8 *pixels, sfColor color);
    void put_background(canvas_t *canvas, sfColor color);
    void pen_down(app_t *app, sfMouseButtonEvent mouse);
    void pen_up(app_t *app, sfMouseButtonEvent mouse);
    void draw(app_t *app, sfMouseMoveEvent mouse);

    //layer
    layer_t *append_layer(layer_t *layer);
    layer_t *create_layer(sfColor color);

    int count_layer(layer_t *layer);

    int create_layer_button(app_t *app);
    int create_preview_button(app_t *app);

    int free_layer(layer_t *layer);

    //slide bar object
    slide_bar_t *init_slide_bar(sfVector2f pos);
    void slider_pressed(slide_bar_t *slide_bar, sfMouseButtonEvent mouse);
    void slider_released(slide_bar_t *slide_bar, sfMouseButtonEvent mouse);
    void slider_move(slide_bar_t *slide_bar, sfMouseMoveEvent mouse);
    void display_slide_bar(sfRenderWindow *window, slide_bar_t *slide_bar);
    slide_bar_t **create_slide_bar_array(unsigned int number,
        sfVector2f *positions);

    //saving & loading
    int save_image(app_t *app);
    int load_image(app_t *app);
    void update_loaded_file(app_t *app);
    char *get_path(path_type_t type);
    void auto_save(app_t *app, bool_t save);
    void set_title(app_t  *app, char *path);
    int concat_layer(app_t *app);

    //brush type callback
    void pencil_action(app_t *app, int status);
    void eraser_action(app_t *app, int status);

    //color button callback
    void b_alloc_color(app_t *app, int status);

    //color button background
    void b_alloc_color_bg(app_t *app, int status);

    void brush_circle(app_t *app, int status);
    void brush_rectangle(app_t *app, int status);
    void brush_normal(app_t *app, int status);

    void do_nothing(app_t *app, int status);

    void b_save_image(app_t *app, int status);
    void b_save_as_image(app_t *app, int status);
    void b_load_image(app_t *app, int status);

    //layer button
    void add_layer(app_t *app, int status);
    void delete_layer(app_t *app, int status);

    void about(app_t *app, int status);

#endif //BASE_REPO_PROTOTYPE_H
