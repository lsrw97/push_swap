/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:34:35 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/17 12:34:50 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

int	costmode(t_stack *nodea, t_stack *nodeb)
{
	int	costup;
	int	costdown;
	int	costseperate;

	costseperate = nodea->cost + nodeb->cost;
	costup = min(nodea, nodeb);
	costdown = max(nodea->index, nodeb->index);
	return (mincost(costseperate, costup, costdown));
}

int	cheapestcost(int i, int j, int x, t_stack *node)
{
	if (i <= j && i <= x)
	{
		node->smode = 1;
		return (i);
	}
	else if (j <= i && j <= x)
	{
		node->smode = 2;
		return (j);
	}
	node->smode = 3;
	return (x);
}

int	realcost(t_stack *nodea, t_stack *nodeb)
{
	int	costup;
	int	costdown;
	int	costseperate;

	costseperate = nodea->cost + nodeb->cost;
	costup = max(nodea->index, nodeb->index);
	costdown = min(nodea, nodeb);
	nodeb->fcosts = cheapestcost(costseperate, costup, costdown, nodeb);
	return (nodeb->fcosts);
}

t_stack	*findcheapest(t_stack **stack)
{
	int		cheapest;
	int		tmp;
	t_stack	*cnode;
	t_stack	*node;

	node = *stack;
	cnode = node;
	cheapest = realcost(node->fnode, node);
	while (node)
	{
		tmp = realcost(node->fnode, node);
		if (tmp < cheapest)
		{
			cheapest = tmp;
			cnode = node;
		}
		node = node->next;
	}
	return (cnode);
}

int	nodesizedown(t_stack *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->prev;
	}
	return (counter);
}
