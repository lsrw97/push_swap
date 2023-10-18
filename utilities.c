/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:15:25 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/17 12:50:04 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

void	sortbycosta(t_stack **stacka, t_stack *node)
{
	if (node->isupper)
	{
		while (node->cost)
		{
			ra(stacka, 1);
			node->cost = node->cost - 1;
		}
	}
	else
	{
		while (node->cost)
		{
			rra(stacka, 1);
			node->cost = node->cost - 1;
		}
	}
}

void	sortbycostb(t_stack **stackb, t_stack *node)
{
	if (node->isupper)
	{
		while (node->cost)
		{
			rb(stackb, 1);
			node->cost = node->cost - 1;
		}
	}
	else
	{
		while (node->cost)
		{
			rrb(stackb, 1);
			node->cost = node->cost - 1;
		}
	}
}

void	sortmodesep(t_stack **stacka, t_stack **stackb, t_stack *node)
{
	t_stack	*fnode;

	fnode = node->fnode;
	sortbycosta(stacka, fnode);
	sortbycostb(stackb, node);
	pa(stacka, stackb);
}

void	updateindex(t_stack	**stack)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = *stack;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}
