/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** ai.h
*/

#ifndef AI_H_
    #define AI_H_

    #include <unistd.h>

typedef struct distance {
    int right;
    int left;
    int middle_right;
    int middle_left;
    int front;
} distance_t;

typedef struct status {
    size_t finish_line;
    int forward;
    float speed;
    distance_t *distance;
} status_t;

int launch_ai(void);

#endif
