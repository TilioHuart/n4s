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

    status->right_distance = 0;
    for (size_t i = 27; i < 33; i += 1) {
        status->right_distance += atoi(arr[i]);
        nb_value += 1;
    }
    status->right_distance /= nb_value;
    fprintf(stderr, "right = %d\n", status->right_distance);
    return SUCCESS;
}

static int retrieve_right_middle_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    status->right_distance = 0;
    for (size_t i = 22; i < 27; i += 1) {
        status->right_middle_distance += atoi(arr[i]);
        nb_value += 1;
    }
    status->right_middle_distance /= nb_value;
    fprintf(stderr, "right middle = %d\n", status->right_middle_distance);
    return SUCCESS;
}

static int retrieve_left_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    status->left_distance = 0;
    for (size_t i = 1; i < 7; i += 1) {
        status->left_distance += atoi(arr[i]);
        nb_value += 1;
    }
    status->left_distance /= nb_value;
    fprintf(stderr, "left = %d\n", status->left_distance);
    return SUCCESS;
}

static int retrieve_left_middle_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    status->left_distance = 0;
    for (size_t i = 7; i < 13; i += 1) {
        status->left_middle_distance += atoi(arr[i]);
        nb_value += 1;
    }
    status->left_middle_distance /= nb_value;
    fprintf(stderr, "left middle = %d\n", status->left_middle_distance);
    return SUCCESS;
}

static int retrieve_front_distance(char **arr, status_t *status)
{
    int nb_value = 0;

    status->front_distance = 0;
    for (size_t i = 12; i < 22; i += 1) {
        status->front_distance += atoi(arr[i]);
        nb_value += 1;
    }
    status->front_distance /= nb_value;
    fprintf(stderr, "front = %d\n", status->front_distance);
    return SUCCESS;
}

int retrieve_information(status_t *status)
{
    char buf[256];
    char **arr = NULL;

    printf("GET_INFO_LIDAR\n");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    arr = my_str_to_word_array(buf,
        "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ :");
    if (check_size_information(arr) < 34)
        return 1;
    retrieve_front_distance(arr, status);
    retrieve_left_middle_distance(arr, status);
    retrieve_left_distance(arr, status);
    retrieve_right_middle_distance(arr, status);
    retrieve_right_distance(arr, status);
    fprintf(stderr, "------------------------------------\n");
    return SUCCESS;
}
