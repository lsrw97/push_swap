#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

// sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

// sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

// rr : ra and rb at the same time.

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

// rrr : rra and rrb at the same time.

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
	return stack;
}

void	sa(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *tmp2;
	t_stack	*lastnode;

	if (ft_nodesize(*stack) == 1)
		return;
	lastnode = ft_nodelast(*stack);
	tmp = ft_newnode(0, NULL);
	tmp2 = ft_newnode(0, NULL);
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

void	ra(t_stack **stack)
{
	t_stack	*lastnode;
	t_stack *tmp;
	t_stack *tmp2;

	if (ft_nodesize(*stack) < 3)
	{
		sa(stack);
		return;
	}
	tmp = ft_newnode(0, NULL);
	tmp = *stack;
	lastnode = ft_nodelast(*stack);
	tmp2 = lastnode->prev;
	lastnode->prev = NULL;
	lastnode->next = tmp;
	tmp->prev = lastnode;
	tmp2->next = NULL;
	*stack = lastnode;
	ft_printf("ra\n");
}

void	rra(t_stack **stack)
{
	t_stack	*lastnode;
	t_stack *tmp;
	t_stack *tmp2;

	if (ft_nodesize(*stack) < 3)
	{
		sa(stack);
		return;
	}
	tmp = ft_newnode(0, NULL);
	tmp = *stack;
	lastnode = ft_nodelast(*stack);
	tmp2 = tmp->next;
	tmp->prev = lastnode;
	tmp->next = NULL;
	lastnode->next = tmp;
	tmp2->prev = NULL;
	*stack = tmp2;
	ft_printf("rra\n");
}

void	push(t_stack **stack, t_stack *node)
{
	t_stack	*lastnode;

	if (!*stack)
	{
		*stack = node;
		return;
	}
	lastnode = ft_nodelast(*stack);
	lastnode->next = node;
	node->next = NULL;
	node->prev = lastnode;


}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack *lastnode;
	t_stack *tmp;

	if (!*stacka)
		return;
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
		return;
	}
	lastnode->next = NULL;
	lastnode->prev = NULL;
	push(stackb, lastnode);
	ft_printf("pb\n");
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	t_stack *lastnode;
	t_stack *tmp;

	if (!*stackb)
		return;
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
		return;
	}
	lastnode->next = NULL;
	lastnode->prev = NULL;
	push(stacka, lastnode);
	ft_printf("pa\n");
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

void	getBiggestNbToTop(t_stack **stack, int index)
{
	int	top;
	int	nodesize;
	int	i;

	nodesize = ft_nodesize(*stack);
	if (index == nodesize)
		return;
	if (nodesize / 2 >= index)
	{
		// printf("i = %d, nodesize = %d, index = %d\n", i, nodesize, index);
		while (index)
		{
			rra(stack);
			index--;
		}
	}
	else
	{
		i = nodesize - index;
		// printf("i = %d, nodesize = %d, index = %d\n", i, nodesize, index);
		while (i)
		{
			ra(stack);
			i--;
		}
	}
}

void	getsmallestnbtotop(t_stack **stack, int index)
{
	int	top;
	int	nodesize;
	int	i;

	nodesize = ft_nodesize(*stack);
	if (index == nodesize)
		return;
	if (nodesize / 2 >= index)
	{
		// printf("i = %d, nodesize = %d, index = %d\n", i, nodesize, index);
		while (index)
		{
			rra(stack);
			index--;
		}
	}
	else
	{
		i = nodesize - index;
		// printf("i = %d, nodesize = %d, index = %d\n", i, nodesize, index);
		while (i)
		{
			ra(stack);
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
	j = 0;
	len = 0;
	while (++j < argc)
	{
		i = -1;
		while(args[j][++i])
			str[len++] = args[j][i];
		str[len++] = ' ';
	}
	str[--len] = '\0';
	return (str);
}

