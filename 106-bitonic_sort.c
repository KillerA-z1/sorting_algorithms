#include "sort.h"
#include <stdio.h>

void bitonic_recursive(int *array, int left, int right,
		int direction, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, int left, int right, int direction);

/**
 * bitonic_sort - sorts an array using the Bitonic sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursive(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursive - recursive function for bitonic sort
 * @array: array to sort
 * @left: index of the left-most element
 * @right: index of the right-most element
 * @direction: ascending or descending
 * @size: size of the array
 */
void bitonic_recursive(int *array, int left,
		int right, int direction, size_t size)
{
	int step;
	size_t range = right - left + 1;

	if (range >= 2)
	{
		step = range / 2;

		printf("Merging [%lu/%lu] ", range, size);
		printf("(%s):\n", direction ? "UP" : "DOWN");
		print_array(array + left, range);

		bitonic_recursive(array, left, left + step - 1, 1, size);
		bitonic_recursive(array, left + step, right, 0, size);
		bitonic_merge(array, left, right, direction);

		printf("Result [%lu/%lu] ", range, size);
		printf("(%s):\n", direction ? "UP" : "DOWN");
		print_array(array + left, range);
	}
}

/**
 * bitonic_merge - sorts and merges a sequence in ascending or descending order
 * @array: array to sort
 * @left: index of the left-most element
 * @right: index of the right-most element
 * @direction: ascending or descending
 */
void bitonic_merge(int *array, int left, int right, int direction)
{
	int tmp, i, step = (right - left + 1) / 2;

	while (step > 0)
	{
		for (i = left; i < left + step; i++)
		{
			if (direction == (array[i] > array[i + step]))
			{
				tmp = array[i + step];
				array[i + step] = array[i];
				array[i] = tmp;
			}
		}
		step /= 2;
	}
}
