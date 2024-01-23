#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers using insertion
 *
 * @list: the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *p_ptr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	ptr = (*list)->next;
	while (ptr != NULL)
	{
		p_ptr = ptr->prev;
		while (p_ptr != NULL && ptr->n < p_ptr->n)
		{
			temp = p_ptr->next;
			p_ptr->next = ptr->next;
			ptr->next = temp;
			if (ptr->next != NULL)
				ptr->next->prev = ptr;
			if (p_ptr->next != NULL)
				p_ptr->next->prev = p_ptr;
			temp = p_ptr->prev;
			p_ptr->prev = ptr->prev;
			ptr->prev = temp;
			if (ptr->prev != NULL)
				ptr->prev->next = ptr;
			else
				(*list) = ptr;
			if (p_ptr->prev != NULL)
				p_ptr->prev->next = p_ptr;
			p_ptr = ptr->prev;
			print_list(*list);
		}
		ptr = ptr->next;
	}
}
