#include "lists.h"

/**
 * check_cycle - Check if a linked list have a cycle.
 * @list: Linked list.
 * Return: 0 Have not cycle, 1 if yes.
 */

int check_cycle(listint_t *list)
{
	listint_t *temp1 = list, *temp2 = list;

	while (temp1 && temp2 && temp2->next)
	{
		temp1 = temp1->next;
		temp2 = temp2->next->next;
		if (temp1 == temp2)
			return (1);
	}
	return (0);
}
