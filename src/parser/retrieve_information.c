/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** retrieve_information.c
*/

#include "my_macros.h"
#include "my.h"
#include "ai.h"
#include <stdio.h>
#include <stdlib.h>

static size_t check_size_information(char **arr)
{
    size_t len = 0;

    if (arr == NULL)
        return FAILURE;
    for (size_t i = 0; arr[i] != NULL; i += 1)
        len += 1;
    return len;
}

static int retrieve_right_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    status->distance->right = 0;
    for (size_t i = 27; i < 33; i += 1) {
        status->distance->right += atoi(arr[i]);
        nb_value += 1;
    }
    status->distance->right /= nb_value;
    return SUCCESS;
}

static int retrieve_right_middle_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    for (size_t i = 32; i < 37; i += 1) {
        status->distance->middle_right += atoi(arr[i]);
        nb_value += 1;
    }
    status->distance->middle_right /= nb_value;
    return SUCCESS;
}

static int retrieve_left_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    status->distance->left = 0;
    for (size_t i = 6; i < 13; i += 1) {
        status->distance->left += atoi(arr[i]);
        nb_value += 1;
    }
    status->distance->left /= nb_value;
    return SUCCESS;
}

static int retrieve_left_middle_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    for (size_t i = 13; i < 19; i += 1) {
        status->distance->middle_left += atoi(arr[i]);
        nb_value += 1;
    }
    status->distance->middle_left /= nb_value;
    return SUCCESS;
}

static int retrieve_front_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    for (size_t i = 19; i < 25; i += 1) {
        status->distance->front += atoi(arr[i]);
        nb_value += 1;
    }
    status->distance->front /= nb_value;
    return SUCCESS;
}

int retrieve_information(status_t *status)
{
    char buf[256];
    char **arr = NULL;

    printf("GET_INFO_LIDAR\n");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    arr = my_str_to_word_array(buf, " :");
    if (check_size_information(arr) < 34)
        return 1;
    retrieve_front_distance(arr, status);
    retrieve_left_middle_distance(arr, status);
    retrieve_left_distance(arr, status);
    retrieve_right_middle_distance(arr, status);
    retrieve_right_distance(arr, status);
    status->distance->left_radius = atoi(arr[6]);
    status->distance->right_radius = atoi(arr[37]);
    return SUCCESS;
}
