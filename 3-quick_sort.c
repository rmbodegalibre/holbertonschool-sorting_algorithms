#include <stdio.h>
#include "sort.h"
void organize(int *array, int first_pos, int last_pos, size_t size);
int fraction(int *array, int first_pos, int last_pos, size_t size);
void toswap(int *a, int *b);

/**
 * quick_sort - Checks if there are contents in the input matrix
 * If true, calls the organize function
 * If false, doesn't do nothing
 *
 * @array: the array containing the integers
 * @size: Is the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	organize(array, 0, (int)(size - 1), size);
}

/**
 * organize - recursively sorts the contents of an array,
 * by using the quick sort algorithm
 * @array: Array containing integers
 * @first_pos: Index of the first element of the array
 * @last_pos: Index of the last element of the array
 * @size: Size of the array
 */

void organize(int *array, int first_pos, int last_pos, size_t size)
{
	int pivot_ini;

	if (first_pos >= last_pos)
		return;
	pivot_ini = fraction(array, first_pos, last_pos, size);
	organize(array, first_pos, pivot_ini - 1, size);
	organize(array, pivot_ini + 1, last_pos, size);
}

/**
 * fraction - Function that applies the Lomuto fraction method.
 * The elements of the matrix that are between the first and last index
 * from the location of the pivot
 * elements smaller than the pivot will be in the left group
 * the elements greater than the pivot will be in the right hand group
 * the last element is always taken as the pivot.
 *
 * @array: The array
 * @first_pos: index of the first element of the array
 * @last_pos: Index of the last element of the array
 * @size: Size of the array
 * Return: Returns the new index taken by the pivot.
 */

int fraction(int *array, int first_pos, int last_pos, size_t size)
{
	int i, pivot_ini = first_pos;
	int pivot = array[last_pos];

	for (i = first_pos; i <= last_pos; i++)
	{
		if (array[i] < pivot)
		{
			if (array[i] != array[pivot_ini])
			{
				toswap(array + i, array + pivot_ini);
				print_array((const int *)array, size);
			}
			pivot_ini++;
		}
	}
	if (array[pivot_ini] != array[last_pos])
	{
		toswap(array + pivot_ini, array + last_pos);
		print_array((const int *)array, size);
	}
	return (pivot_ini);
}

/**
 * toswap - This function swaps received integers with each other.
 * @a: Left side integer
 * @b: Right side integer
 */

void toswap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
