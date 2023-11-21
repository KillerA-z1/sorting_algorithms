#include "sort.h"

void heapify(int *array, size_t heap_size, size_t root, size_t size);

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t current, heap_size;
	int tmp;

	if (array == NULL || size < 2)
		return;

	heap_size = size;
	current = heap_size / 2;
	while (current > 0)
	{
		current--;
		heapify(array, heap_size, current, size);
	}

	while (heap_size > 1)
	{
		tmp = array[heap_size - 1];
		array[heap_size - 1] = array[0];
		array[0] = tmp;
		print_array(array, size);
		heap_size--;
		heapify(array, heap_size, 0, size);
	}
}

/**
 * heapify - Turns an array into a heap.
 * @array: Array to turn into a heap.
 * @heap_size: Size of the current heap.
 * @root: Index of the subtree root in the heap.
 * @size: Size of the whole array.
 */
void heapify(int *array, size_t heap_size, size_t root, size_t size)
{
	size_t max_child, left_child, right_child;
	int tmp;

	while (root < heap_size)
	{
		max_child = root;
		left_child = (2 * root) + 1;
		right_child = (2 * root) + 2;

		if (left_child < heap_size && array[left_child] > array[max_child])
			max_child = left_child;

		if (right_child < heap_size && array[right_child] > array[max_child])
			max_child = right_child;

		if (max_child != root)
		{
			tmp = array[root];
			array[root] = array[max_child];
			array[max_child] = tmp;
			print_array(array, size);
			root = max_child;
		}
		else
		{
			break;
		}
	}
}
