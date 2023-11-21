#include "sort.h"

void handle(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array with elements
 * @size: size of array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	handle(array, 0, size - 1, size);
}

/**
 * handle - Recursively sorts sub-arrays using quicksort
 * @array: array with elements
 * @low: index of the lower bound of the sub-array
 * @high: index of the higher bound of the sub-array
 * @size: size of array
 *
 * Return: Nothing
 */
void handle(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		handle(array, low, pi - 1, size);
		handle(array, pi + 1, high, size);
	}
}

/**
 * partition - Lomuto partition scheme to sort sub-arrays
 * @array: array with elements
 * @low: index of the lower bound of the sub-array
 * @high: index of the higher bound of the sub-array
 * @size: size of array
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int tmp, j;
	int pivot = array[high];
	int i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
