#include "../includes/push_swap.h"


void sort_3(my_stack *a)
{
	int top;
	int mid;
	int bot;

	if (a->size != 3)
		return;
	top = a->array[0];
	mid = a->array[1];
	bot = a->array[2];

	// 3 1 2 /
	if (top > mid && mid < bot && top > bot)
	{
		ra(a, 1);
	}
	// 2 3 1 /
	else if (top < mid && top < bot && mid > bot)
	{
		rra(a, 1);
	}
	// 2 1 3 /
	else if (mid < top && bot > top && bot > mid) 
	{
			sa(a, 1);
	}
	// 1 3 2 /
	else if (mid > top && mid > bot && bot > top)
	{
		sa(a, 1);
		ra(a, 1);
	}
	// 3 2 1 /
	else if (top > mid && top > bot && mid > bot)
	{
		sa(a, 1);
		rra(a, 1);
	}
	// 1 2 3
	else if (top < mid && mid < bot)
        return;
}