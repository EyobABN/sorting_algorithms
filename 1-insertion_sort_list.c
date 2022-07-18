#include "sort.h"

/**
 * insertion_sort_list - insertion list algorithm
 * @list: the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c, *s, *p, *pp, *sn;
	int first = 1;

	if (list == NULL || *list == NULL)
		return;
	for (c = *list; c != NULL; c = c->next)
	{
		if (first)
		{
			first = 0;
			continue;
		}
		s = c;
		while (s != NULL && s->prev != NULL && s->n < s->prev->n)
		{
			/* switch s and s->prev */
			p = s->prev;
			pp = p->prev;
			sn = s->next;
			p->next = sn;
			s->next = p;
			s->prev = pp;
			p->prev = s;
			if (sn != NULL)
				sn->prev = p;
			if (pp != NULL)
				pp->next = s;
			if (s->prev == NULL)
				*list = s;

			print_list(*list);
		}
	}
}
