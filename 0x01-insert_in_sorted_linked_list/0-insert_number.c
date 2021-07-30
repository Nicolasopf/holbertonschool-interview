#include "lists.h"


/**
 * insert_node - Insert a node depending of the value.
 * @head: pointer to the head of the list.
 * @number: num to insert in node.
 * Return: NULL if error, otherwise, the new node.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL, *tmp = NULL;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = number;

	if (!*head)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}
	else if ((*head)->n >= number)
	{
		new->next = *head;
		*head = new;
	}
	else
		for (tmp = *head; tmp; tmp = tmp->next)
			if (tmp->n < number)
				if (!tmp->next || tmp->next->n > number)
				{
					new->next = tmp->next;
					tmp->next = new;
					break;
				}

	return (new);
}
