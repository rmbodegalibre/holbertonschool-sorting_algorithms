#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order.
 * using the Bubble sort algorithm
 * @array: array to sort.
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
    unsigned int cross, position, to_swap, check_order;

    if (!size || !array || size < 2)
        return;

    for (cross = 0; cross <= size; cross++)
    {
        check_order = 0;

        for (position = 0; position < size - 1; position++)
        {
            if (array[position] > array[position + 1])
            {
                to_swap = array[position];
                array[position] = array[position + 1];
                array[position + 1] = to_swap;
                print_array(array, size);

                check_order = 1;
            }
        }
        if (check_order == 0)
            break;
    }
}