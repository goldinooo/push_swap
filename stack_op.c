#include "../includes/push_swap.h"

my_stack *start_stack(int capacity)
{
	my_stack *stack;
	stack = (my_stack *)malloc(sizeof(my_stack));
	if (!stack)
		return NULL;
	stack->array = (int *)malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return NULL;
	}
	stack->size = 0;
	stack->capacity = capacity;
	return stack;
}	

void free_stack(my_stack *stack)
{
	if (stack)
	{
		if(stack->array)
			free(stack->array);
		free(stack);
	}
}

void sa(my_stack *a, int print)
{
	int tmp;
	if(a->size < 2)
		return;
	tmp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = tmp;
	if (print)
		write(1, "sa\n", 3);		
}

void sb(my_stack *b, int print)
{
	int tmp;
	if(b->size < 2)
		return;
	tmp = b->array[0];
	b->array[0] = b->array[1];
	b->array[1] = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void ss(my_stack *a, my_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void pa(my_stack *a, my_stack *b)
{
	int idx = a->size;
	if (b->size == 0 || (a->size >= a->capacity))     // Check if Stack B is empty or if Stack A is full
		return;
	while (idx > 0)
	{
		a->array[idx] = a->array[idx - 1]; // shift all stack b up by 1
		idx--;
	}
	a->array[0] = b->array[0];
	idx = 0;
	while (idx < b->size - 1)
	{
		b->array[idx] = b->array[idx + 1];
		idx++; 
	}
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

void pb(my_stack *a, my_stack *b)
{
	int idx = b->size;
	if (a->size == 0 || (b->size >= b->capacity))
		return;
	while (idx > 0)
	{
		b->array[idx] = b->array[idx - 1];
		idx--;
	}
	b->array[0] = a->array[0];
	idx = 0;
	while (idx < a->size - 1)
	{
		a->array[idx] = a->array[idx + 1];
		idx++;
	}
	b->size++;
	a->size--;
	write(1, "pb\n", 3);
}

void ra(my_stack *a, int print)
{
	int size = a->size;
	int tmp;
	int idx = 0;
	if (size < 2)
		return;
	tmp = a->array[0];
	while (idx < size - 1)
	{
		a->array[idx] = a->array[idx + 1];
		idx++;
	}
	a->array[size - 1] = tmp;
	if (print)
		write(1, "ra\n", 3);
}

void rb(my_stack *b, int print)
{
	int size = b->size;
	int tmp;
	int idx = 0;
	if (size < 2)
		return;
	tmp = b->array[0];
	while (idx < size - 1)
	{
		b->array[idx] = b->array[idx + 1];
		idx++;
	}
	b->array[size - 1] = tmp;
	if (print)
		write(1, "rb\n", 3);
}

void rr(my_stack *a, my_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void rra(my_stack *a, int print)
{
	int tmp;
	int i;
	if (a->size < 2)
		return;
	tmp = a->array[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	if (print)
		write(1, "rra\n", 4);
}

void rrb(my_stack *b, int print)
{
	int tmp;
	int i;
	if (b->size < 2)
		return;
	tmp = b->array[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
	if (print)
		write(1, "rrb\n", 4);
}

void rrr(my_stack *a, my_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}