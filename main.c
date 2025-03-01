#include "../includes/push_swap.h"

#include <stdio.h>

int main(void)
{
	my_stack lol;
	int idx = 0;
	int tab[3] = {0,100,1000};
	lol.array = tab;
	lol.capacity = 3;
	lol.size = 3;
	sort_3(&lol);
	// printf("%d", );
	// sa(&lol, 1);
	while (idx < lol.size)
	{
		printf("%d ", lol.array[idx]);
		idx++;
	}
	write(1, "\n", 1);
	return 0;
}