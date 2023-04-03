/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** prototype.h
*/

#ifndef MY_STRING_H_
    #define MY_STRING_H_

    #include <unistd.h>
    #include <stdlib.h>

    int my_strlen(const char *str);

    int my_putstr(const char *str);
    int my_putchar(const char character);

    char *my_strcat(char *dest, const char *src);
    char *my_strncat(char *dest, const char *src, int n);
    int my_strappend(char *dest, const char character);

    char *my_strcpy(char *dest, const char *src);
    char *my_strncpy(char *dest, const char *src, int n);

    int my_strcmp(const char *str_1, const char *str_2);
    int my_strncmp(const char *str_1, const char *str_2, int n);

    char *my_strdup(const char *src);
    char *my_revstr(char *str);
    int my_strerror(int errnum);

#endif
