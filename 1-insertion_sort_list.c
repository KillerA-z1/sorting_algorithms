#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the linked list.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *unsorted_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		insertion_point = current->prev;
		unsorted_node = current;

		while (insertion_point != NULL && insertion_point->n > unsorted_node->n)
		{
			if (insertion_point->prev != NULL)
				insertion_point->prev->next = unsorted_node;
			else
				*list = unsorted_node;

			if (unsorted_node->next != NULL)
				unsorted_node->next->prev = insertion_point;

			unsorted_node->prev = insertion_point->prev;
			insertion_point->prev = unsorted_node;
			insertion_point->next = unsorted_node->next;
			unsorted_node->next = insertion_point;

			insertion_point = unsorted_node->prev;

			if (unsorted_node->prev == NULL)
				*list = unsorted_node;

			print_list(*list);
		}
	}
}
