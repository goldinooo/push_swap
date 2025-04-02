/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 02:57:46 by retahri           #+#    #+#             */
/*   Updated: 2025/04/02 08:43:18 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

/**   includes    **/

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int 	content;
	int 	pos;
	struct s_stack *next;	
} 	t_stack;

/**   utils.c    **/
void error(void);
void check_nums(char **av, int sub, int idx);
void check(char **av);
void nodup(t_stack *stack, t_stack *node);

/**   utils2.c    **/
size_t ft_strlen(char *s);
int is_digit(int nb);
int	ft_atoi(const char *str);
int	ft_array_len(char	**array);
char	*ft_strdup(char *s1);

/**   list_utils.c    **/
void lst_add_front(t_stack **lst, t_stack *node);
void lst_add_back(t_stack **lst, t_stack *node);
t_stack *ft_bumplst(t_stack *lst);
size_t ft_lstsize(t_stack *lst);
t_stack *ft_lstnew(long long content);

/**   split.c    **/
char	**ft_split(char	const *s, char c);

/**   handler.c    **/
void free_arr(char **arr);
void is_valid(char *str, char **arr);
char **simplify(int *ac, char **av);

#endif