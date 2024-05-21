#include <stdio.h>
#include <stddef.h>

/**
 * print_array - Helper function to print the array being searched.
 * @array: Pointer to the first element of the array to search in.
 * @low: The lower index of the range to search.
 * @high: The upper index of the range to search.
 */
void print_array(int *array, size_t low, size_t high)
{
    printf("Searching in array: ");
    for (size_t i = low; i <= high; i++)
    {
        printf("%d", array[i]);
        if (i < high)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursive helper function for advanced binary search.
 * @array: Pointer to the first element of the array to search in.
 * @low: The lower index of the range to search.
 * @high: The upper index of the range to search.
 * @value: The value to search for.
 *
 * Return: The first index where value is located or -1 if value is not found.
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
    size_t mid;

    if (low <= high)
    {
        print_array(array, low, high);

        mid = low + (high - low) / 2;

        if (array[mid] == value && (mid == low || array[mid - 1] != value))
            return (mid);

        if (array[mid] >= value)
            return (advanced_binary_recursive(array, low, mid, value));
        else
            return (advanced_binary_recursive(array, mid + 1, high, value));
    }

    return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array using Advanced binary search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located or -1 if value is not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
