/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:32:56 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/18 13:46:20 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

int	issorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->nb < stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sortthree(t_stack **stack)
{
	if (!issorted(*stack))
	{
		if (smallestindex(stack) == 1 && biggestindex(stack) == 3)
		{
			sa(stack);
			rra(stack, 1);
		}
		else if (smallestindex(stack) == 1 && biggestindex(stack) == 2)
			rra(stack, 1);
		else if (smallestindex(stack) == 2 && biggestindex(stack) == 3)
			ra(stack, 1);
		else if (smallestindex(stack) == 2 && biggestindex(stack) == 1)
			sa(stack);
		else
		{
			rra(stack, 1);
			sa(stack);
		}
	}
}

void	smallsort(t_stack **stack)
{
	if (ft_nodesize(*stack) == 1)
		return ;
	if (ft_nodesize(*stack) == 2 && !issorted(*stack))
		sa(stack);
	if (ft_nodesize(*stack) == 3 && !issorted(*stack))
		sortthree(stack);
}

int	friendscore(int num, int num2)
{
	if (num < 0)
		return ((num - num2) * -1);
	return (num - num2);
}

void	setfriendnode(t_stack *nodea, t_stack *nodeb)
{
	nodeb->fscore = nodea->nb - nodeb->nb;
	nodeb->fnode = nodea;
}
