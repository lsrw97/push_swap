// we split the first argument into seperate strings with ft_split
// each string will be converted into a number with ft_atoi and stored in a int array
// we need an index variable to store the height of the stacks



#include <stdio.h>
#include "libft/libft.h"
#include "push.h"

void iter(t_stack* next, t_stack* prev)
{
	printf("next: %d, prev: %d\n", next->nb, prev->nb);
}

t_stack *findbiggestnumber(t_stack *node){
	int num;
	t_stack *tmp;
	t_stack *biggest;

	if(!node)
		return (NULL);
	if(!node->next)
		return (node);
	tmp = node;
	biggest = node;
	num = tmp->nb;
	while(tmp)
	{
		if(tmp->nb > num)
			{
				num = tmp->nb;
				biggest = tmp;
			}
		tmp = tmp->next;
	}
	return (biggest);
}

int	checkdoubles(t_stack *node)
{
	int	nb;
	t_stack *current;
	t_stack *index;

	current = node;
	index = node->next;
	while(current)
	{
		nb = current->nb;
		while(index)
		{
			if(nb == index->nb)
				return (0);
			index = index->next;
		}
		current = current->next;
	}
	return (1);
}

t_stack *createstack(char *arr, int size)
{
	t_stack *node;
	t_stack *nodetmp;
	int		i;

	if(!size)
	return NULL;
	i = 2;

	node = ft_newnode(ft_atoi(arr[1]), NULL);
	if (arr[2])
	{
	node->next = ft_newnode(ft_atoi(arr[2]), node);
	nodetmp = node->next;
	}
	else
		return node;
	while (++i < size)
	{
		nodetmp->next = ft_newnode(ft_atoi(arr[i]), nodetmp);
		nodetmp = nodetmp->next;
	}
	return node;
}

int main (int argc, char *args[])
{
	// t_stack **stacka;
	// t_stack **stackb;
	// t_stack *nodea;
	// t_stack *nodeb;
	// t_stack *nodetmp;

	struct t_stack stacka;
	t_stack *start;


	start = &stacka;

	stacka.nb = 2;
	start->nb = 4;

	// printf("%d, start: %p", stacka.nb, start);

	start->next = ft_newnode(5, start);

	printf("%p", stacka.next);

	// if (argc < 2)
	// {
	// 	printf("list must contain at least one element!");
	// 	return 0;
	// }
	// nodea = (createstack(args, argc));
	// stacka = &nodea;
	// nodeb = (createstack(args, 0));
	// stackb = &nodeb;
	// nodetmp = nodea;
	// 	// pb(stacka, stackb);
	// sa(*stacka);

	// // printf("B(0) %d\n", (*stacka)->nb);
	// printf("A(1) %d\n", (*stacka)->nb);
	// printf("A(2) %d\n", (*stacka)->next->nb);
	// printf("A(3) %d\n", (*stacka)->next->next->nb);



	// printf("Biggest Number: %d\n", findbiggestnumber((*stacka))->nb);
	// printf(" %d\n", checkdoubles((*stacka)));
	// printf(" %p\n", (*stackb));


// 		while(1){
		// pb(stacka, stackb);
// 		pb(stacka, stackb);
// 		if(ft_nodesize(*stacka) == 1)
// 		{
// 			nodea = NULL;
// 			break;
// 		}
// }

// algorithm

// while(*stacka)
// {
// 	t_stack *node;
// 	int	count;
// 	int stacksize;

// 	node = ft_newnode(1, NULL);


// 	// nodea = NULL;
// 	// printf("%p, %p\n", ft_nodelast((*stacka)), nodetmp);
 
// 	// pb(stacka, stackb);


	// printf("(4) %d\n", (*stacka)->next->next->next->nb);
	// printf("(5) %d\n", (*stacka)->next->next->next->next);
// 	printf("(1a) %d\n", (*stackb)->nb);
// 	while (nodea)
// 	{
// 		printf("%d\n", nodea->nb);
// 		nodea = nodea->next;
// 	}
// 	 return 0;
// }
}
