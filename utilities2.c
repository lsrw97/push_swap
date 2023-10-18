/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:32:23 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/18 13:09:20 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

int	detectpair(t_stack **stack_a, t_stack **stack_b, int diff)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stackb = *stack_b;
	stacka = *stack_a;
	diff = stacka->nb - stackb->nb;
	while (stacka)
	{
		if (stacka->nb - stackb->nb > 0)
		{
			if (stackb->fscore < 0
				|| stacka->nb - stackb->nb < stackb->fscore)
			{
				setfriendnode(stacka, stackb);
				diff = stacka->nb - stackb->nb;
			}
		}
		else if (diff < 0 && diff > stacka->nb - stackb->nb)
		{
			setfriendnode(stacka, stackb);
			diff = stacka->nb - stackb->nb;
		}
		stacka = stacka->next;
	}
	return (diff);
}

int	biggestindex(t_stack **stack)
{
	t_stack	*node;
	int		biggest;
	int		i;
	int		j;

	i = 1;
	j = 1;
	node = *stack;
	biggest = node->nb;
	while (node)
	{
		if (biggest < node->nb)
		{
			j = i;
			biggest = node->nb;
		}
		i++;
		node = node->next;
	}
	return (j);
}

int	smallestindex(t_stack **stack)
{
	t_stack	*node;
	int		smallest;
	int		i;
	int		j;

	i = 1;
	j = 1;
	node = *stack;
	smallest = node->nb;
	while (node)
	{
		if (smallest > node->nb)
		{
			j = i;
			smallest = node->nb;
		}
		i++;
		node = node->next;
	}
	return (j);
}

void	getsmallestnbtotop(t_stack **stack, int index)
{
	int	nodesize;
	int	i;

	nodesize = ft_nodesize(*stack);
	if (index == nodesize)
		return ;
	if (nodesize / 2 >= index)
	{
		while (index)
		{
			rra(stack, 1);
			index--;
		}
	}
	else
	{
		i = nodesize - index;
		while (i)
		{
			ra(stack, 1);
			i--;
		}
	}
}

char	*concatargs(char **args, int argc)
{
	int		i;
	int		len;
	char	*str;
	int		j;

	i = 0;
	len = 0;
	str = "";
	while (++i != argc)
		len += ft_strlen(args[i]);
	len += argc - 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	j = 0;
	len = 0;
	while (++j < argc)
	{
		i = -1;
		while (args[j][++i])
			str[len++] = args[j][i];
		str[len++] = ' ';
	}
	str[--len] = '\0';
	return (str);
}
