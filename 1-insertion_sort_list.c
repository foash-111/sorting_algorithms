#include"sort.h"

/**
 * swap_nodes - swap between 2 nodes
 * @first_node: first number
 * @second_node: second number
 * Return: (nothing)
*/

void swap_nodes(listint_t *first_node, listint_t *second_node)
{
	if (first_node->prev == NULL && second_node->next == NULL)
	{
		second_node->next = first_node;
		second_node->prev = NULL;
		first_node->prev = second_node;
		first_node->next = NULL;
	}
	else if (first_node->prev == NULL && second_node->next != NULL)
	{
		first_node->next = second_node->next;
		second_node->next->prev = first_node;
		first_node->prev = second_node;
		second_node->next = first_node;
		second_node->prev = NULL;
	}
	else if (first_node->prev != NULL && second_node->next == NULL)
	{
		second_node->prev = first_node->prev;
		first_node->prev->next = second_node;
		first_node->next = NULL;
		first_node->prev = second_node;
		second_node->next = first_node;
	}
	else if (first_node->prev != NULL && second_node->next != NULL)
	{
		first_node->prev->next = first_node->next;
		second_node->prev = first_node->prev;
		first_node->next = second_node->next;
		first_node->prev = second_node;
		second_node->next = first_node;
		first_node->next->prev = first_node;
	}

}

/**
 * insertion_sort_list - insertion_sort algorithm emplementing on linked list
 * @list: our pointer to our double linked list
 * Return(nothing)
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *current = *list;
	int key = 0, flag = 0;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;
	if (head != NULL)
	head = head->next;

	while (head)
	{
		key = head->n;
		current = head->prev;
		while ((current) && (current->n > key))
		{
			swap_nodes(current, current->next);
			if (current->prev->prev == NULL && (current->n > key))
			(*list) = current->prev;
			if (flag == 0)
			{
				head = head->next;
				flag = 1;
			}
			print_list((const listint_t *)*list);

			current = current->prev->prev;
		}
		head = head->next;
		flag = 0;
	}
}
