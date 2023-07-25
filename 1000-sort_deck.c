#include "deck.h"

/**
 * sort_deck - sorts a deck of cards
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
deck_node_t *current, *next;

if (!deck || !(*deck) || !(*deck)->next)
return;

current = *deck;
next = current->next;

while (next)
{
if (next->card->kind < current->card->kind)
{
if (current->prev)
current->prev->next = next;
else
*deck = next;
next->prev = current->prev;
current->prev = next;
current->next = next->next;
next->next = current;
if (current->next)
current->next->prev = current;
current = *deck;
next = current->next;
continue;
}
current = current->next;
next = current->next;
}
}
