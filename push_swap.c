/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:50:56 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/18 13:11:55 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

void	freesplit(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	freestack(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (stack)
	{
		stack = stack->next;
		free(node);
		node = stack;
	}
}

t_stack	*createstack(char **arr, int size)
{
	t_stack	*stack;
	t_stack	*tmp;
	char	**split;
	char	*str;

	if (size == 0)
		return (NULL);
	str = concatargs(arr, size);
	split = ft_split(str, ' ');
	if (!checkfornan(split, str) || !checkforinteger(split, str))
		return (NULL);
	size = arglen(split);
	stack = ft_newnode(ft_atoi(split[--size]), NULL);
	tmp = stack;
	while (--size >= 0)
	{
		tmp->next = ft_newnode(ft_atoi(split[size]), tmp);
		tmp = tmp->next;
	}
	free(str);
	freesplit(split);
	if (!checkfordoubles(stack))
		return (NULL);
	return (stack);
}

void	sortseq(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	setpairs(stack_a, stack_b);
	setuppercostnode(stack_b);
	setuppercostnode(stack_a);
	node = findcheapest(stack_b);
	sortmodesep(stack_a, stack_b, node);
	updateindex(stack_a);
	updateindex(stack_b);
}

int	main(int argc, char *args[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = createstack(args, argc);
	stack_b = NULL;
	if (!stack_a || issorted(stack_a))
	{
		freestack(stack_a);
		return (0);
	}
	if (ft_nodesize(stack_a) < 4)
	{
		smallsort(&stack_a);
		freestack(stack_a);
		return (0);
	}
	while (*(&stack_a->next->next->next))
		pb(&stack_a, &stack_b);
	sortthree(&stack_a);
	while (stack_b)
		sortseq(&stack_a, &stack_b);
	getsmallestnbtotop(&stack_a, smallestindex(&stack_a));
	freestack(stack_a);
}
