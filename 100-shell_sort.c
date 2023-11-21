#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using shell sort algorithm
 *              with Knuth sequence.
 * @array: The array of integers.
 * @size: Size of the array.
 *
 * Return: None.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && tmp < array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
