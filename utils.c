#include "../includes/push_swap.h"

int is_space(char c)
{
	return((c >= 9 && c <= 13) || c == 32);
}
int is_digit(char c)
{
	return(c >= '0' && c <= '9');
}
void werror(void)
{
	write(2, "error :(\n", 9);
}
int is_sorted(my_stack *a)
{
	int i = 0;
	int size = a->size;
	while (i < size - 1)
	{
		if (a->array[i] > a->array[i + 1])
			return 0;
		i++;
	}
	return 1;
}