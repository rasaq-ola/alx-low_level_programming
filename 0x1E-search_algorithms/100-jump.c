#include <stdio.h>
#include <math.h>
#include <stddef.h>

/**
 * jump_search - Searches for a value in a sorted array using Jump search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located or -1 if value is not found.
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size);
    size_t prev = 0;
    size_t curr = 0;

    if (array == NULL || size == 0)
        return (-1);

    // Jump through the array to find the block where the value could be
    while (curr < size && array[curr] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
        prev = curr;
        curr += step;
    }

    // Check if we overshoot
    if (curr >= size)
        curr = size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);

    // Linear search within the identified block
    for (size_t i = prev; i <= curr && i < size; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (i);
    }

    return (-1);
}
