#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *out_arr;
	size_t i, max = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}
	count_arr = malloc((max + 1) * sizeof(int));
	out_arr = malloc(size * sizeof(int));
	if (count_arr == NULL || out_arr == NULL)
	{
		free(count_arr);
		free(out_arr);
		return;
	}

	for (i = 0; i <= max; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;
	for (i = 1; i <= max; i++)
		count_arr[i] += count_arr[i - 1];
	for (i = 0; i < size; i++)
	{
		out_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = out_arr[i];
	print_array(count_arr, max + 1);

	free(count_arr);
	free(out_arr);
}
