/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:33:18 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/18 13:10:06 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

void	setpairs(t_stack **stack_a, t_stack **stack_b)
{
	int		diff;
	t_stack	*stacka;
	t_stack	*stackb;

	stackb = *stack_b;
	stacka = *stack_a;
	diff = 0;
	while (stackb)
	{
		setfriendnode(stacka, stackb);
		diff = detectpair(&stacka, &stackb, diff);
		stacka = *stack_a;
		stackb = stackb->next;
	}
}

void	setuppercostnode(t_stack **stack)
{
	int		size;
	int		index;
	t_stack	*node;

	node = ft_nodelast(*stack);
	index = 0;
	size = ft_nodesize(*stack);
	while (node)
	{
		if (size / 2 >= index)
			node->isupper = 1;
		else
			node->isupper = 0;
		if (!node->isupper)
			node->cost = size - index;
		else
			node->cost = index;
		node->index = index;
		node = node->prev;
		index++;
	}
}

int	max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}

int	min(t_stack *a, t_stack *b)
{
	int	sizea;
	int	sizeb;

	sizea = nodesizedown(a);
	sizeb = nodesizedown(b);
	if (sizea > sizeb)
		return (sizea);
	return (sizeb);
}

int	mincost(int i, int j, int x)
{
	if (i < j && i < x)
		return (1);
	else if (j < i && j < x)
		return (2);
	else
		return (3);
}
