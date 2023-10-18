/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:46:03 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/17 16:22:05 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

void	rrb(t_stack **stack, int i)
{
	t_stack	*lastnode;
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_nodesize(*stack) < 3)
	{
		sb(stack);
		return ;
	}
	tmp = *stack;
	lastnode = ft_nodelast(*stack);
	tmp2 = tmp->next;
	tmp->prev = lastnode;
	tmp->next = NULL;
	lastnode->next = tmp;
	tmp2->prev = NULL;
	*stack = tmp2;
	if (i)
		ft_printf("rrb\n");
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	ra(stacka, 0);
	rb(stackb, 0);
	ft_printf("rr\n");
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rra(stacka, 0);
	rrb(stackb, 0);
	ft_printf("rrr\n");
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack	*lastnode;
	t_stack	*tmp;

	if (!*stacka)
		return ;
	lastnode = ft_nodelast(*stacka);
	if (ft_nodesize(*stacka) > 1)
	{
		tmp = lastnode->prev;
		tmp->next = NULL;
	}
	else
	{
		push(stackb, lastnode);
		*stacka = NULL;
		ft_printf("pb\n");
		return ;
	}
	lastnode->next = NULL;
	lastnode->prev = NULL;
	push(stackb, lastnode);
	ft_printf("pb\n");
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	t_stack	*lastnode;
	t_stack	*tmp;

	if (!*stackb)
		return ;
	lastnode = ft_nodelast(*stackb);
	if (ft_nodesize(*stackb) > 1)
	{
		tmp = lastnode->prev;
		tmp->next = NULL;
	}
	else
	{
		push(stacka, lastnode);
		*stackb = NULL;
		ft_printf("pa\n");
		return ;
	}
	lastnode->next = NULL;
	lastnode->prev = NULL;
	push(stacka, lastnode);
	ft_printf("pa\n");
}
