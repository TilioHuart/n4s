/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** main_branch.c
*/

#include "my_macros.h"
#include "ai.h"
#include <stdio.h>

int main_branch(status_t *status)
{
    if (status->distance->front >= 200 && status->forward == FALSE) {
        fprintf(stderr, "front = %d\n", status->distance->front);
        printf("CAR_FORWARD:%f\n", status->speed);
        status->forward = TRUE;
    }
    if (status->forward == TRUE && status->distance->front < 400) {
        fprintf(stderr, "STOP\n");
        printf("CAR_BACKWARDS:%f\n", status->speed);
    }
    return SUCCESS;
}
