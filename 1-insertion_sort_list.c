#include "sort.h"

/**
 * insertion_sort_list - check the code
 * @list: est un double pointeur vers une structure
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !(*list)->next)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *key = current;
		listint_t *prev = current->prev;

		while (prev != NULL && prev->n > key->n)
			prev = prev->prev;

		if (prev != current->prev)
		{
			if (current->next)
				current->next->prev = current->prev;
			if (current->prev)
				current->prev->next = current->next;

			if (prev->prev)
				prev->prev->next = key;
			key->prev = prev->prev;
			key->next = prev;
			prev->prev = key;

			if (key->prev == NULL)
				*list = key;
		}

		current = current->next;
	}
}
