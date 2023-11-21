#include "sort.h"

/**
 * switch_nodes - Function that sorts a doubly linked list of integers in
 *		ascending order using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 * @current: Pointer to the current node to be swapped.
 */
void switch_nodes(listint_t **list, listint_t **current)
{
	listint_t *prev_node, *next_node, *current_node;

	prev_node = (*current)->prev;
	current_node = *current;
	next_node = (*current)->next;

	current_node->next = next_node->next;
	if (next_node->next)
		next_node->next->prev = current_node;

	next_node->prev = prev_node;
	next_node->next = current_node;

	current_node->prev = next_node;

	if (prev_node)
		prev_node->next = next_node;
	else
		*list = next_node;

	*current = next_node;
}

/**
 * cocktail_sort_list - Function sorts a doubly linked list using the
 * cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 *
 * Description: The cocktail shaker sort is a variation of the bubble sort.
 * It sorts the list in both directions (from left to right and right to left).
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int sorted = 0;

	if (!list || !*list || (*list)->next == NULL)
		return;

	current = *list;
	while (!sorted)
	{
		sorted = 1;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				sorted = 0;
				switch_nodes(list, &current);
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (sorted)
			break;

		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				sorted = 0;
				current = current->prev;
				switch_nodes(list, &current);
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
