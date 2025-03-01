#include "../includes/push_swap.h"

static int atoi_valid(char *s, long *n)
{
	int i = 0;
	int sign = 1;
	long res = 0;

	while (is_space(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if(!is_digit(s[i]))
		return (0);
	while (is_digit(s[i]))
	{
		res *= 10;
		res += (s[i] - '0');

		i++;
	}
	*n = res * sign;
	return 1;
}

static int has_dup(my_stack *a, int value)
{
	int i = 0;
	while (i < a->size)
	{
		if (a->array[i] == value)
			return 1;
		i++;
	}
	return 0;
}

int parse(int ac, char **av, my_stack *a)
{
	int i = 1;
	long n;

	if (ac < 2)
		return 0;
	while (i < ac)
	{
		if (!atoi_valid(av[i], &n))
			return 0;
		if (has_dup(a, n))
			return (0);
		a->array[a->size] = n;
		a->size++;
		i++;
	}
	return 1;
}
