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
    return  SUCCESS;
}

int launch_ai(void)
{
    status_t *status = malloc(sizeof(status_t));

    printf("START_SIMULATION\n");
    if (init_status(status) == FAILURE)
        return EPITECH_FAILURE;
    while (status->finish_line != TRUE) {
        retrieve_information();
    }
    free(status);
    return SUCCESS;
}
