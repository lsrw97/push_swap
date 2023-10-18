/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:39 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/17 18:34:10 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

int	ft_nodesize(t_stack *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

t_stack	*ft_newnode(int nb, t_stack *prev)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->next = NULL;
	list->prev = prev;
	return (list);
}

t_stack	*ft_nodelast(t_stack *lst)
{
	t_stack	*lastnode;

	lastnode = lst;
	if (!lst)
		return (NULL);
	while (lastnode->next)
		lastnode = lastnode->next;
	return (lastnode);
}

t_stack	*getfirstnode(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

void	push(t_stack **stack, t_stack *node)
{
	t_stack	*lastnode;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	lastnode = ft_nodelast(*stack);
	lastnode->next = node;
	node->next = NULL;
	node->prev = lastnode;
}
