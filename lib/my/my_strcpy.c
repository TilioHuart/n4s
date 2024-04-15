/*
** EPITECH PROJECT, 2023
** MY_STRCPY
** File description:
** Copy a string inside another one
*/

#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
