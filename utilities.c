
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

	list = (t_stack *)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->next = NULL;
    list->prev = prev;
	if(!prev)
		list->id = 1;
	else
		list->id = list->prev->id + 1;
	return (list);
}

void	ft_nodeadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lastnode;

	if (*lst)
	{
		lastnode = ft_nodelast(*lst);
		lastnode->next = new;
		lastnode->prev = ft_nodelast(*lst);
		(*lst)->next = lastnode;
	}
	else
		lst = &new;
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

void	ft_nodeiter(t_stack *lst, void (*f)(int))
{
	t_stack	*node;

	node = lst;
	if (!f || !node)
		return ;
	while (node->next)
	{
		f(node->nb);
		node = node->next;
	}
	if (!node->next)
		f(node->nb);
}

void	ft_nodeitermod(t_stack *lst, void (*f)(t_stack*, t_stack*))
{
	t_stack	*node;

	node = lst;
	if (!f || !node)
		return ;
	while (node->next)
	{
		f(node->next, node->prev);
		node = node->next;
	}
		// if(!node->next)
		//     f(node->next, node->prev);
}

// node1 <-> tmpnode <-> lstnode ->
// visualize this on ipad. start at node1 and initialize the next node. lstnode change prev and next, tmpnode change prev.

void sa(t_stack *stack)
{
	t_stack *lastnode;
	t_stack *tmpnode;
	t_stack *tmpnode2;

	int tmp;

	lastnode = ft_nodelast(stack);	// 1 2
	if (lastnode->prev->prev)
	{
		tmpnode = lastnode->prev->prev;
		tmpnode2 = lastnode->prev;
		printf("%d\n%p,\n%p\n", tmpnode->nb, tmpnode2->next, lastnode);
		tmpnode->next = lastnode;
		printf("%p\n%p,\n%p", tmpnode->next, tmpnode2->next, lastnode);
		lastnode->prev = tmpnode->prev;
		tmpnode->next = tmpnode2;
		tmpnode2->prev = tmpnode;
	}
	else
		lastnode->prev;				//1


	// lastnode->prev = lastnode;	//2 2
	// lastnode = tmpnode;	//2 1
}

void	ra(t_stack *stack)
{
	t_stack *lastnode;
	int tmp;

	// tmp = stack->nb;
	// lastnode = ft_nodelast(stack);	// 1 2 3
	// stack->nb = lastnode->nb;
	tmp = stack->nb;
	lastnode = stack;
	while (lastnode->next)
	{
		lastnode->nb = lastnode->next->nb;
		lastnode = lastnode->next;
	}
	lastnode->nb = tmp;
}

void	rr(t_stack *stack)
{
	t_stack *lastnode;
	int tmp;

	lastnode = ft_nodelast(stack);
	tmp = lastnode->nb;
	while (lastnode->prev)
	{
		lastnode->nb = lastnode->prev->nb;
		lastnode = lastnode->prev;
	}
	stack->nb = tmp;
	lastnode = ft_nodelast(stack);
}

int	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack *node;
	t_stack *tmp;
	
	if (!(*stackb))
	{
		node = ft_nodelast(*stacka);
		tmp = ft_newnode(node->nb, NULL);
		*stackb = tmp;
		node = node->prev;
		node->next = NULL;
	}
	else{
		node = ft_nodelast(*stacka);
		tmp = ft_nodelast(*stackb);
		tmp->next = ft_newnode(node->nb, tmp);
		if(!node->prev)
			*stacka = NULL;
		else
		{
			node = node->prev;
			node->next = NULL;
		}
	}
	return 1;
}

int	pa(t_stack **stackb, t_stack **stacka)
{
	t_stack *node;
	t_stack *tmp;
	
	if (!(*stackb))
	{
		node = ft_nodelast(*stacka);
		tmp = ft_newnode(node->nb, NULL);
		*stackb = tmp;
		node = node->prev;
		node->next = NULL;
	}
	else{
		node = ft_nodelast(*stacka);
		tmp = ft_nodelast(*stackb);
		tmp->next = ft_newnode(node->nb, tmp);
		if(!node->prev)
			*stacka = NULL;
		else
		{
			node = node->prev;
			node->next = NULL;
		}
	}
	return 1;
}