#include "sort.h"

void count_sort_LSD(int *array, size_t size, size_t lsd);

/**
 * radix_sort - Sorts an array using the Radix sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_value;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	max_value = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max_value)
			max_value = array[i];

	lsd = 1;
	while (max_value / lsd > 0)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
		lsd *= 10;
	}
}

/**
 * count_sort_LSD - Count sort with LSD
 * @array: Array to sort
 * @size: Size of the array
 * @lsd: Least significant digit
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0};
	int *out_arr;
	size_t k, m, n;

	out_arr = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		count_arr[(array[k] / lsd) % 10]++;
	for (m = 1; m < 10; m++)
		count_arr[m] += count_arr[m - 1];

	m = size - 1;
	while (m != (size_t)-1)
	{
		out_arr[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
		count_arr[(array[m] / lsd) % 10]--;
		m--;
	}

	n = 0;
	while (n < size)
	{
		array[n] = out_arr[n];
		n++;
	}

	free(out_arr);
}
