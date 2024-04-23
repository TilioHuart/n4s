/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** ai.c
*/

#include "my_macros.h"
#include "ai.h"
#include "retrieve_information.h"
#include "main_branch.h"
#include <stdio.h>
#include <stdlib.h>

static int init_status(status_t *status)
{
    if (status == NULL)
        return FAILURE;
    status->distance = malloc(sizeof(distance_t));
    if (status->distance == NULL)
        return FAILURE;
    status->distance->front = 0;
    status->distance->middle_left = 0;
    status->distance->left = 0;
    status->distance->middle_right = 0;
    status->distance->right = 0;
    status->finish_line = FALSE;
    status->forward = FALSE;
    status->left = FALSE;
    status->right = FALSE;
    status->speed = 0.3;
    return SUCCESS;
}

int launch_ai(void)
{
    status_t *status = malloc(sizeof(status_t));

    printf("START_SIMULATION\n");
    if (init_status(status) == FAILURE)
        return EPITECH_FAILURE;
    while (status->finish_line != TRUE) {
        retrieve_information(status);
        fflush(stdout);
        if (main_branch(status) == FAILURE)
            return FAILURE;
    }
    free(status);
    return SUCCESS;
}
