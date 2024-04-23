/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** main_branch.c
*/

#include "my_macros.h"
#include "ai.h"
#include <stdio.h>

static void handle_speed(status_t *status)
{
    if ((status->distance->front >= 1500 && status->forward == FALSE) ||
        (status->distance->left >= 300 && status->forward == FALSE) ||
        (status->distance->right >= 300 && status->forward == FALSE)) {
        printf("CAR_FORWARD:0.3\n");
        fprintf(stderr, "normal speed with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->forward = TRUE;
        status->left = FALSE;
    }
    if ((status->distance->front <= 1500 && status->forward == TRUE) ||
        (status->distance->left <= 300 && status->forward == TRUE) ||
        (status->distance->right <= 300 && status->forward == TRUE)) {
        printf("CAR_FORWARD:0.1\n");
        fprintf(stderr, "less speed with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->forward += 1;
    }
    if ((status->distance->front >= 1500 && status->distance->right >= 300
        && status->distance->left >= 300 && status->forward > TRUE)) {
        status->forward = FALSE;
        fprintf(stderr, "return normal speed with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
    }
}

static void handle_left(status_t *status)
{
    if (status->distance->left_radius <= 250) {
        printf("WHEELS_DIR:-1\n");
        printf("CYCLE_WAIT:2\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn immediately right with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        return;
    }
    if ((status->distance->middle_left <= 1600 && status->distance->front <=
        1300 && status->distance->right > status->distance->left && status->left == FALSE)) {
        printf("WHEELS_DIR:-0.5\n");
        printf("CYCLE_WAIT:2\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn first right with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->left += 1;
        return;
    }
    if (status->distance->middle_left <= 1100 && status->distance->left >= 500 && status->left >= TRUE) {
        printf("WHEELS_DIR:-0.5\n");
        printf("CYCLE_WAIT:1\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn a little right with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
    }
    if ((status->distance->left <= 300 && status->distance->front <= 600 &&
        status->distance->right > status->distance->left && status->left >= TRUE)) {
        printf("WHEELS_DIR:-1\n");
        printf("CYCLE_WAIT:3\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn very right with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        return;
    }
    if ((status->distance->left <= 500 && status->distance->front <= 1100 &&
        status->distance->right > status->distance->left && status->left >= TRUE)) {
        printf("WHEELS_DIR:-1\n");
        printf("CYCLE_WAIT:2\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn right with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        return;
    }
}

static void handle_right(status_t *status)
{
    if (status->distance->right_radius <= 250) {
        printf("WHEELS_DIR:1\n");
        printf("CYCLE_WAIT:2\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn immediately left with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        return;
    }
    if ((status->distance->middle_right <= 1600 && status->distance->front <=
        1300 && status->distance->right < status->distance->left && status->right == FALSE)) {
        printf("WHEELS_DIR:0.5\n");
        printf("CYCLE_WAIT:2\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn first left with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        status->left += 1;
        return;
    }
    if (status->distance->middle_right <= 1100 && status->distance->right >= 500 && status->right >= TRUE) {
        printf("WHEELS_DIR:0.5\n");
        printf("CYCLE_WAIT:1\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn a little left with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
    }
    if ((status->distance->right <= 300 && status->distance->front <= 600 &&
        status->distance->right < status->distance->left && status->right >= TRUE)) {
        printf("WHEELS_DIR:1\n");
        printf("CYCLE_WAIT:3\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn very left with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
        return;
    }
    if ((status->distance->right <= 500 && status->distance->front <= 1100 &&
        status->distance->right < status->distance->left && status->right >= TRUE)) {
        printf("WHEELS_DIR:1\n");
        printf("CYCLE_WAIT:2\n");
        printf("WHEELS_DIR:0.0\n");
        fprintf(stderr, "turn left with %d front and %d left and %d right\n", status->distance->front, status->distance->left, status->distance->right);
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
    last_front = status->distance->front;
    last_left = status->distance->left;
    return SUCCESS;
}
