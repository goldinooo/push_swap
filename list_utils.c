/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 05:46:28 by retahri           #+#    #+#             */
/*   Updated: 2025/04/02 06:00:41 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstnew(long long content)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

size_t ft_lstsize(t_stack *lst)
{
	int idx;

	idx = 0;
	while (lst)
	{
		lst = lst->next;
		idx++;
	}
	return (idx);	
}
t_stack *ft_bumplst(t_stack *lst)
{
	if (!lst)
		return (NULL);
	if (lst)
		lst = lst->next;
	return (lst);
}

void lst_add_back(t_stack **lst, t_stack *node)
{
	if (!lst || !node)
		return;
	if (*lst)
		ft_bumplst(*lst)->next = node;
	else
		*lst = node;
}

void lst_add_front(t_stack **lst, t_stack *node)
{
	if (!lst || !node)
		return;
	node->next = *lst;
	*lst = node;
}