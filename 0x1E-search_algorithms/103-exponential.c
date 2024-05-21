#include <stdio.h>
#include <stddef.h>

/**
 * binary_search - Helper function for binary search in exponential search.
 * @array: Pointer to the first element of the array to search in.
 * @low: The lower index of the range to search.
 * @high: The upper index of the range to search.
 * @value: The value to search for.
 *
 * Return: The index where value is located or -1 if value is not found.
 */
int binary_search(int *array, size_t low, size_t high, int value)
{
    size_t mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        printf("Searching in array: ");
        for (size_t i = low; i <= high; i++)
        {
            printf("%d", array[i]);
            if (i < high)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
            return (mid);
        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array using Exponential search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located or -1 if value is not found.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    if (array == NULL || size == 0)
        return (-1);

    if (array[0] == value)
        return (0);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t low = bound / 2;
    size_t high = (bound < size) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", low, high);
    return (binary_search(array, low, high, value));
}
