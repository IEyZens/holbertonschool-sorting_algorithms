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
		listint_t *target = current;
		listint_t *prev = current->prev;

		while (prev != NULL && prev->n > target->n)
			prev = prev->prev;

		if (prev != current->prev)
		{
			if (current->next)
				current->next->prev = current->prev;
			if (current->prev)
				current->prev->next = current->next;

			if (prev == NULL)
			{
				target->next = *list;
				target->prev = NULL;
				(*list)->prev = target;
				*list = target;
			}
			else
			{
				target->next = prev->next;
				if (prev->next)
					prev->next->prev = target;
				prev->next = target;
				target->prev = prev;
			}
		}

		current = current->next;
	}
}
