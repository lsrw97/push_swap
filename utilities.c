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

void	ra(t_stack **stack, int i)
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
	if (i)
		ft_printf("ra\n");
}

void	rra(t_stack **stack, int i)
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
	if (i)
		ft_printf("rra\n");
}

void	rb(t_stack **stack, int i)
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
	if (i)
		ft_printf("rb\n");
}

void	rrb(t_stack **stack, int i)
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
			rra(stack, 1);
			index--;
		}
	}
	else
	{
		i = nodesize - index;
		// printf("i = %d, nodesize = %d, index = %d\n", i, nodesize, index);
		while (i)
		{
			ra(stack, 1);
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
			rra(stack, 1);
			index--;
		}
	}
	else
	{
		i = nodesize - index;
		// printf("i = %d, nodesize = %d, index = %d\n", i, nodesize, index);
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

int	isstorted(t_stack *stack)
{
	while(stack)
	{
		if(stack->next && stack->nb < stack->next->nb)
			return 0;
		stack = stack->next;
	}
	return 1;
}

void	sortthree(t_stack **stack)
{
	if (!isstorted(*stack))
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
		else if(smallestindex(stack) == 2 && biggestindex(stack) == 1)
				sa(stack);
		else
			{
				rra(stack, 1);
				sa(stack);
			}
	}
}

void	smallsort(t_stack *stack)
{
	if(ft_nodesize(stack) == 1)
		return;
	if (ft_nodesize(stack) == 2 && !isstorted(stack))
		sa(&stack);
	if (ft_nodesize(stack) == 3 && !isstorted(stack))
		sortthree(&stack);
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

void	setpairs(t_stack **stack_a, t_stack **stack_b)
{
	int	diff;
	int tmp;
	t_stack *node;
	t_stack *stacka;
	t_stack *stackb;

	stackb = *stack_b;
	stacka = *stack_a;
	node = stacka;
	diff = 0;
	while (stackb)
	{
		setfriendnode(stacka, stackb);
		while (stacka)
		{
			if (stacka->nb - stackb->nb > 0)
				if(stackb->fscore < 0 || stacka->nb - stackb->nb < stackb->fscore)
					setfriendnode(stacka, stackb);
			// printf("----stacka: %d, stackb: %d, pair: %d\n",stacka->nb, stackb->nb, stackb->fscore);
			stacka = stacka->next;
		}
		// printf("----stackb: %d, pair: %d\n", stackb->nb, stackb->fscore);
		stacka = *stack_a;
		stackb = stackb->next;
	}
}


void	setuppercostnode(t_stack **stack)
{
	int	size;
	int	index;
	t_stack *node;

	node = ft_nodelast(*stack);
	index = 0;
	size = ft_nodesize(*stack);
	// printf("size: %d\n", size);
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
	int sizea;
	int sizeb;

	sizea = nodesizedown(a);
	sizeb = nodesizedown(b);
	// printf("sizea: %d, sizeb: %d\n", sizea, sizeb);
	if (sizea > sizeb)
		return (sizea);
	return (sizeb);
}

int mincost(int i, int j, int x)
{
	if (i > j && i > x)
		return 1;
	else if (j > i && j > x)
		return 2;
	else
		return 3;
}

int	costmode(t_stack *nodea, t_stack *nodeb)
{
	int	costup;
	int costdown;
	int	costseperate;

	costseperate = nodea->cost + nodeb->cost; // 70 cost 3, 72 cost 
	costup = min(nodea, nodeb);
	costdown = max(nodea->index, nodeb->index);
	return (mincost(costseperate, costup, costdown));
}

int cheapestcost(int i, int j, int x, t_stack *node)
{
	if (i <= j && i <= x)
	{
		node->smode = 1;
		return i;
	}
	else if (j <= i && j <= x)
	{
		node->smode = 2;
		return j;
	}
	node->smode = 3;
	return x;
}

int realcost(t_stack *nodea, t_stack *nodeb)
{
	int	costup;
	int costdown;
	int	costseperate;

	costseperate = nodea->cost + nodeb->cost; // 70 cost 3, 72 cost 
	costup = max(nodea->index, nodeb->index);
	costdown = min(nodea, nodeb);
	// printf("costseperate: %d, costup: %d, costdown: %d, nodea: %d, nodeb: %d\n", nodea->cost + nodeb->cost, max(nodea->index, nodeb->index), min(nodea, nodeb), nodea->nb, nodeb->nb);
	nodeb->fcosts = cheapestcost(costseperate, costup, costdown, nodeb);
	return (nodeb->fcosts);
}

t_stack	*findcheapest(t_stack *node)
{
	int	cheapest;
	int tmp;
	t_stack	*cnode;

	cnode = node;

	cheapest = realcost(cnode->fnode, cnode);
	while (node)
	{
		// printf("node->fnode->cost: %d, node->cost: %d\n", node->fnode->cost, node->cost);
		tmp = realcost(node->fnode, node);
		if (tmp < cheapest)
		{
			cheapest = tmp;
			cnode = node;
		}
		// printf("cheapest: %d\n", cheapest);
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
	t_stack *fnode;

	fnode = node->fnode;
	// printf("fnode: %d\n", fnode->nb);
	sortbycosta(stacka, fnode);
	sortbycostb(stackb, node);
	pa(stacka, stackb);
}

void sortmodeup(t_stack **stacka, t_stack **stackb, t_stack *node)
{
	t_stack *fnode;
	int		sizea;
	int		sizeb;

	fnode = node->fnode;
	sizea = ft_nodesize(fnode) - 1;
	sizeb = ft_nodesize(node) - 1;
	// printf("sizea: %d, sizeb: %d\n", sizea, sizeb);
	if (sizea <= sizeb)
	{
		while (sizea)
		{
			rr(stacka, stackb);
			sizea--;
			sizeb--;
		}
		while (sizeb)
		{
			rb(stackb, 1);
			sizeb--;
		}
	}
	else
	{
		while (sizeb)
		{
			rr(stacka, stackb);
			sizea--;
			sizeb--;		
		}
		while (sizea)
		{
			ra(stacka, 1);
			sizea--;
		}
	}
	pa(stacka, stackb);
}

void sortmodedown(t_stack **stacka, t_stack **stackb, t_stack *node)
{
	t_stack *fnode;
	int		sizea;
	int		sizeb;

	fnode = node->fnode;
	sizea = nodesizedown(fnode);
	sizeb = nodesizedown(node);
	// printf("sizea: %d, sizeb: %d\n", sizea, sizeb);
	if (sizea <= sizeb)
	{
		while (sizea)
		{
			rrr(stacka, stackb);
			sizea--;
			sizeb--;
		}
		while (sizeb)
		{
			rrb(stackb, 1);
			sizeb--;
		}
	}
	else
	{
		while (sizeb)
		{
			rrr(stacka, stackb);
			sizea--;
			sizeb--;		
		}
		while (sizea)
		{
			rra(stacka, 1);
			sizea--;
		}
	}
	pa(stacka, stackb);
}

