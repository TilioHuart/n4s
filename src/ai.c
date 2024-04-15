/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** ai.c
*/

#include "my_macros.h"
#include "ai.h"
#include "retrieve_information.h"
#include <stdio.h>
#include <stdlib.h>

static int init_status(status_t *status)
{
    if (status == NULL)
        return FAILURE;
    status->finish_line = FALSE;
    status->front_distance = -1;
    status->left_distance = -1;
    status->right_distance = -1;
    return SUCCESS;
}

int launch_ai(void)
{
    status_t *status = malloc(sizeof(status_t));

    printf("START_SIMULATION\n");
    if (init_status(status) == FAILURE)
        return EPITECH_FAILURE;
    while (status->finish_line != TRUE) {
        if (retrieve_information(status) == 1)
            continue;
        printf("CAR_FORWARD:0.2\n");
    }
    free(status);
    return SUCCESS;
}
