/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:53:16 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/17 21:22:39 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

void	sa(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*lastnode;

	if (ft_nodesize(*stack) == 1)
		return ;
	lastnode = ft_nodelast(*stack);
	tmp = lastnode->prev;
	if (lastnode->prev->prev)
	{
		tmp2 = lastnode->prev->prev;
		tmp2->next = lastnode;
		lastnode->prev = tmp2;
		lastnode->next = tmp;
	}
	else
	{
		lastnode->prev = NULL;
		lastnode->next = tmp; 
	}
	tmp->prev = lastnode;
	tmp->next = NULL;
	*stack = getfirstnode(*stack);
	ft_printf("sa\n");
}

void	sb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*lastnode;

	if (ft_nodesize(*stack) == 1)
		return ;
	lastnode = ft_nodelast(*stack);
	tmp = lastnode->prev;
	if (lastnode->prev->prev)
	{
		tmp2 = lastnode->prev->prev;
		tmp2->next = lastnode;
		lastnode->prev = tmp2;
		lastnode->next = tmp;
	}
	else
	{
		lastnode->prev = NULL;
		lastnode->next = tmp;
	}
	tmp->prev = lastnode;
	tmp->next = NULL;
	*stack = getfirstnode(*stack);
	ft_printf("sb\n");
}

void	ra(t_stack **stack, int i)
{
	t_stack	*lastnode;
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_nodesize(*stack) < 3)
	{
		sa(stack);
		return ;
	}
	tmp = *stack;
	lastnode = ft_nodelast(*stack);
	tmp2 = lastnode->prev;
	lastnode->prev = NULL;
	lastnode->next = tmp;
	tmp->prev = lastnode;
	tmp2->next = NULL;
	*stack = lastnode;
	if (i)
		ft_printf("ra\n");
}

void	rra(t_stack **stack, int i)
{
	t_stack	*lastnode;
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_nodesize(*stack) < 3)
	{
		sa(stack);
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
		ft_printf("rra\n");
}

void	rb(t_stack **stack, int i)
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
	tmp2 = lastnode->prev;
	lastnode->prev = NULL;
	lastnode->next = tmp;
	tmp->prev = lastnode;
	tmp2->next = NULL;
	*stack = lastnode;
	if (i)
		ft_printf("rb\n");
}
