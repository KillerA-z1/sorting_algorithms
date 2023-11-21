#include "sort.h"

void merge_sort_recursive(int *temp_array, int *array,
				size_t left, size_t right);
void merge_subarray(int *temp_array, int *array,
		size_t left, size_t middle, size_t right);

/**
 * merge_sort - Sorts an array of integers using the Merge Sort algorithm
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (array == NULL || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL)
		return;

	merge_sort_recursive(temp_array, array, 0, size);

	free(temp_array);
}

/**
 * merge_sort_recursive - Recursive function for Merge Sort
 * @temp_array: Temporary array to hold sorted elements.
 * @array: Original array to be sorted.
 * @left: Left index of the subarray.
 * @right: Right index of the subarray.
 */
void merge_sort_recursive(int *temp_array, int *array,
				size_t left, size_t right)
{
	if (right - left > 1)
	{
		size_t middle = (right + left) / 2;
	merge_sort_recursive(temp_array, array, left, middle);
		merge_sort_recursive(temp_array, array, middle, right);
		merge_subarray(temp_array, array, left, middle, right);
	}
}

/**
 * merge_subarray - Merge two subarrays in ascending order.
 * @temp_array: Temporary array to hold sorted elements.
 * @array: Original array.
 * @left: Left index of the first subarray.
 * @middle: Right index of the first and left index of the second subarray.
 * @right: Right index of the second subarray.
 */
void merge_subarray(int *temp_array, int *array,
		size_t left, size_t middle, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
			temp_array[k] = array[i++];
		else
			temp_array[k] = array[j++];
	}

	while (i < middle)
		temp_array[k++] = array[i++];
	while (j < right)
		temp_array[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = temp_array[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
