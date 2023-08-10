#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicate a string to a new memory location
 * @str: input string
 * Return: pointer to the duplicated string, or NULL if allocation fails or input is NULL
 */
char *_strdup(char *str)
{
    if (str == NULL)
        return NULL;

    int length = 0;
    while (str[length] != '\0')
        length++;

    char *duplicate = malloc(sizeof(char) * (length + 1));

    if (duplicate == NULL)
        return NULL;

    for (int i = 0; str[i]; i++)
        duplicate[i] = str[i];

    duplicate[length] = '\0';

    return duplicate;
}
