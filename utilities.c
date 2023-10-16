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
	return stack;
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

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack *lastnode;
	t_stack *tmp;

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
	t_stack *lastnode;
	t_stack *tmp;

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

void	getsmallestnbtotop(t_stack **stack, int index)
{
	int	top;
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

int	isstorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->nb < stack->next->nb)
			return (0);
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
		else if (smallestindex(stack) == 2 && biggestindex(stack) == 1)
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
	if (ft_nodesize(stack) == 1)
		return ;
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
		diff = stacka->nb - stackb->nb;
		while (stacka)
		{
			if (stacka->nb - stackb->nb > 0)
			{
				if(stackb->fscore < 0 || stacka->nb - stackb->nb < stackb->fscore)
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
	if (sizea > sizeb)
		return (sizea);
	return (sizeb);
}

int mincost(int i, int j, int x)
{
	if (i < j && i < x)
		return 1;
	else if (j < i && j < x)
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

int realcost(t_stack *nodea, t_stack *nodeb)
{
	int	costup;
	int costdown;
	int	costseperate;

	costseperate = nodea->cost + nodeb->cost; // 70 cost 3, 72 cost 
	costup = max(nodea->index, nodeb->index);
	costdown = min(nodea, nodeb);
	nodeb->fcosts = cheapestcost(costseperate, costup, costdown, nodeb);
	return (nodeb->fcosts);
}

t_stack	*findcheapest(t_stack **stack)
{
	int	cheapest;
	int tmp;
	t_stack	*cnode;
	t_stack *node;

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
	sortbycosta(stacka, fnode);
	sortbycostb(stackb, node);
	pa(stacka, stackb);
}

// void sortmodeup(t_stack **stacka, t_stack **stackb, t_stack *node)
// {
// 	t_stack *fnode;
// 	int		sizea;
// 	int		sizeb;

// 	fnode = node->fnode;
// 	sizea = ft_nodesize(fnode) - 1;
// 	sizeb = ft_nodesize(node) - 1;
// 	if (sizea <= sizeb)
// 	{
// 		while (sizea)
// 		{
// 			rr(stacka, stackb);
// 			sizea--;
// 			sizeb--;
// 		}
// 		while (sizeb)
// 		{
// 			rb(stackb, 1);
// 			sizeb--;
// 		}
// 	}
// 	else
// 	{
// 		while (sizeb)
// 		{
// 			rr(stacka, stackb);
// 			sizea--;
// 			sizeb--;		
// 		}
// 		while (sizea)
// 		{
// 			ra(stacka, 1);
// 			sizea--;
// 		}
// 	}
// 	pa(stacka, stackb);
// }

// void sortmodedown(t_stack **stacka, t_stack **stackb, t_stack *node)
// {
// 	t_stack *fnode;
// 	int		sizea;
// 	int		sizeb;

// 	fnode = node->fnode;
// 	sizea = nodesizedown(fnode);
// 	sizeb = nodesizedown(node);
// 	if (sizea <= sizeb)
// 	{
// 		while (sizea)
// 		{
// 			rrr(stacka, stackb);
// 			sizea--;
// 			sizeb--;
// 		}
// 		while (sizeb)
// 		{
// 			rrb(stackb, 1);
// 			sizeb--;
// 		}
// 	}
// 	else
// 	{
// 		while (sizeb)
// 		{
// 			rrr(stacka, stackb);
// 			sizea--;
// 			sizeb--;		
// 		}
// 		while (sizea)
// 		{
// 			rra(stacka, 1);
// 			sizea--;
// 		}
// 	}
// 	pa(stacka, stackb);
// }

void	updateindex(t_stack	**stack)
{
	t_stack	*node;
	int	i;

	i = 0;
	node = *stack;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}

// void	sortmode(int i, t_stack **stacka, t_stack **stackb, t_stack *node)
// {
// 	if (i == 1)
// 		sortmodesep(stacka, stackb, node);
// 	else if (i == 2)
// 		sortmodeup(stacka, stackb, node);
// 	else
// 		sortmodedown(stacka, stackb, node);
// }