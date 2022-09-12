#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int cross, cur_position, cur_minimum_position, toswp;

	if (!size || !array || size < 2)
		return;

	for (cross = 0; cross < size - 1; cross++)
	{
		cur_minimum_position = cross;

		for (cur_position = cross; cur_position < size; cur_position++)
		{
			if (array[cur_position] < array[cur_minimum_position])
				cur_minimum_position = cur_position;
		}

		if (cur_minimum_position != cross)
		{
			toswp = array[cross];
			array[cross] = array[cur_minimum_position];
			array[cur_minimum_position] = toswp;

			print_array(array, size);
		}
	}
}
