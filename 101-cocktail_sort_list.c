#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
listint_t *tmp;

if (node1->prev)
node1->prev->next = node2;
else
*list = node2;
if (node2->next)
node2->next->prev = node1;
tmp = node2->next;
node2->next = node1;
node2->prev = node1->prev;
node1->next = tmp;
node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tmp;
int swapped = 1;

if (!list || !*list)
return;
tmp = *list;
while (swapped != 0)
{
swapped = 0;
while (tmp->next)
{
if (tmp->n > tmp->next->n)
{
swap_nodes(list, tmp, tmp->next);
print_list(*list);
swapped = 1;
}
else
tmp = tmp->next;
}
if (swapped == 0)
break;
swapped = 0;
while (tmp->prev)
{
if (tmp->n < tmp->prev->n)
{
swap_nodes(list, tmp->prev, tmp);
print_list(*list);
swapped = 1;
}
else
tmp = tmp->prev;
}
}
}
