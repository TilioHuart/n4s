/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** main_branch.c
*/

#include "my_macros.h"
#include "ai.h"
#include <stdio.h>
#include <unistd.h>

static void handle_speed(status_t *status)
{
    if ((status->distance->front >= 1500 && status->forward == FALSE) ||
        (status->distance->left >= 300 && status->forward == FALSE) ||
        (status->distance->right >= 300 && status->forward == FALSE)) {
        printf("CAR_FORWARD:0.1\n");
        fprintf(stderr, "normal speed with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->forward = TRUE;
        status->left = FALSE;
    }
    if ((status->distance->front >= 1500 && status->distance->right >= 300
        && status->distance->left >= 300 && status->forward > TRUE)) {
        status->forward = FALSE;
        fprintf(stderr, "return normal speed with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
    }
}

static void handle_left(status_t *status)
{
    if (status->distance->right <= status->distance->left &&
        status->distance->front <= 1000 && status->left == FALSE) {
        printf("WHEELS_DIR:0.4\n");
        printf("CYCLE_WAIT:1\n");
        fprintf(stderr, "turn right bijour with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->left = TRUE;
        return;
    }
    if (status->distance->right <= status->distance->left &&
        status->distance->front <= 1000 && status->left_two == FALSE) {
        printf("WHEELS_DIR:0.2\n");
        printf("CYCLE_WAIT:1\n");
        fprintf(stderr, "turn right bijour with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->left_two = TRUE;
        return;
    }
}

static void handle_right(status_t *status)
{
    if (status->distance->left <= status->distance->right &&
        status->distance->front <= 1000 && status->right == FALSE) {
        printf("WHEELS_DIR:-0.4\n");
        printf("CYCLE_WAIT:1\n");
        fprintf(stderr, "turn right bijour with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->right = TRUE;
        return;
    }
    if (status->distance->left <= status->distance->right &&
        status->distance->front <= 1300 && status->right_two == FALSE) {
        printf("WHEELS_DIR:-0.2\n");
        printf("CYCLE_WAIT:1\n");
        fprintf(stderr, "turn right next with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->right_two = TRUE;
        return;
    }
}

int main_branch(status_t *status)
{
    static int last_front = 0;
    static int last_left = 0;
    static int last_right = 0;

    if (last_front == status->distance->front ||
        (last_front > status->distance->front && last_front < (status->distance->front + 35)) ||
        (last_front < status->distance->front && last_front > (status->distance->front - 35))) {
        return SUCCESS;
    }
    if (last_left == status->distance->left ||
        (last_left > status->distance->left && last_left < (status->distance->left + 35)) ||
        (last_left < status->distance->left && last_left > (status->distance->left - 35))) {
        return SUCCESS;
    }
    if (last_right == status->distance->right ||
        (last_right > status->distance->right && last_right < (status->distance->right + 35)) ||
        (last_right < status->distance->right && last_right > (status->distance->right - 35))) {
        return SUCCESS;
    }
    handle_speed(status);
    handle_left(status);
    handle_right(status);
    if ((status->distance->front >= 1300 && status->distance->left >= 400 &&
        status->distance->right >= 400 && status->left == TRUE) ||
        (status->distance->front >= 1300 && status->distance->left >= 400 &&
        status->distance->right >= 400 && status->right == TRUE) ||
        (status->distance->front >= 1300 && status->distance->left >= 400 &&
        status->distance->right >= 400 && status->right_two == TRUE) ||
        (status->distance->front >= 1300 && status->distance->left >= 400 &&
        status->distance->right >= 400 && status->left_two == TRUE)) {
        fprintf(stderr, "reset wheel with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        printf("WHEELS_DIR:0.0\n");
        status->left = FALSE;
        status->right = FALSE;
        status->right_two = FALSE;
        status->left_two = FALSE;
    }
    last_front = status->distance->front;
    last_left = status->distance->left;
    return SUCCESS;
}
