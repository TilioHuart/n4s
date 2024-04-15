/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** ai.h
*/

#ifndef AI_H_
    #define AI_H_

    #include <unistd.h>

typedef struct status {
    size_t finish_line;
    int front_distance;
    int left_distance;
    int right_distance;
} status_t;

int launch_ai(void);

#endif
