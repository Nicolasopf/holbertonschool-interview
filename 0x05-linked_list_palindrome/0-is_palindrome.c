#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Check if a linked list is a palindrome.
 * @head: pointer to head node.
 * Return: 1 if palindrome, 0 if not.
 */

int is_palindrome(listint_t **head)
{
	int nums[1024], index, j;
	listint_t *tmp = *head;

	if (*head)
	{
		for (index = 0; tmp; index++)
		{
			nums[index] = tmp->n;
			tmp = tmp->next;
		}
		for (j = 0; j < index; j++)
			if (nums[j] != nums[index - j - 1])
				return (0);
	}

	return (1);
}
