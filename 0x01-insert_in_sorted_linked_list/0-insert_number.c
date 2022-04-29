#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Adds a node into a sorted list
 * @head: The first node of the list
 * @number: The number of the new node
 *
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *actual = *head;
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *prev = NULL;

	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL || (*head)->n >= number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (actual && number >= actual->n)
	{
		prev = actual;
		actual = actual->next;
	}

	new->next = actual;
	prev->next = new;

	return (new);
}
