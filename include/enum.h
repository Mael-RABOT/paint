/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** enum.h
*/

#ifndef ENUM_H_
    #define ENUM_H_

    #include "prototype.h"

    typedef enum choose_color {
        BACKGROUND = 0,
        BRUSH
    } choose_color_t;

    typedef enum state {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED
    } state_t;

    typedef enum boolean {
        FALSE = 0,
        TRUE
    } bool_t;

    typedef enum brush_type {
        PENCIL = 0,
        ERASER
    } brush_type_t;

    typedef enum brush_mode {
        UP = 0,
        DOWN
    } brush_mode_t;

    typedef enum brush_shape {
        SQUARE = 0,
        CIRCLE,
        RECTANGLE
    } brush_shape_t;

    typedef enum color {
        Black = 0,
        White,
        Red,
        Green,
        Blue,
        Yellow,
        Magenta,
        Cyan
    } color_t;

    typedef enum path_type {
        SAVE = 0,
        LOAD
    } path_type_t;

#endif
