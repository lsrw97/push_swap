// we split the first argument into seperate strings with ft_split
// each string will be converted into a number with ft_atoi and stored in a int array
// we need an index variable to store the height of the stacks



#include <stdio.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

t_stack *createstack(char **arr, int size)
{
	t_stack *stack;
	t_stack *tmp;
	char	**split;
	int		i;

	i = -1;
	if (size == 0)
		return NULL;
	split = ft_split(concatargs(arr, size), ' ');
	if (!checkfornan(split) || !checkforinteger(split))
		return NULL;
	size = arglen(split);
	stack = ft_newnode(ft_atoi(split[--size]), NULL);
	tmp = stack;
	while(--size >= 0)
	{
		tmp->next = ft_newnode(ft_atoi(split[size]), tmp);
		tmp = tmp->next;
	}
	if (!checkfordoubles(stack))
		return NULL;
	return stack;
}

int main (int argc, char *args[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack *node;
	int		*pos;

	stack_a = createstack(args, argc);
	stack_b = NULL;
	if (!stack_a)
		return 0;
int i = 250;
while(*(&stack_a->next->next->next))
// while(--i)
	pb(&stack_a, &stack_b);

// printf("small: %d\n", smallestindex(&stack_a));
// printf("big: %d\n", biggestindex(&stack_a));
sortthree(&stack_a);




while (stack_b)
{
setpairs(&stack_a, &stack_b);
setuppercostnode(&stack_b);
setuppercostnode(&stack_a);
node = findcheapest(stack_b);
// printf("\ncheapest is: %d, fcosts: %d, stacka: %d, stackb: %d\n\n", node->nb, node->fcosts, stack_b->fnode->nb, stack_b->nb);
// printf("%d\n", stack_b->nb);
// printf("stack_a = %d\n", stack_a->nb);
// rra(&stack_a, 1);
sortmodesep(&stack_a, &stack_b, node);
}

getsmallestnbtotop(&stack_a, smallestindex(&stack_a));



		// printf("stacka: %d, pair: %d\n", stack_a->nb, stack_a->pairnode);

	// while(stack_a)
	// {
	// 	// printf("stacka: %d, pair: %d\n", stack_a->nb, stack_a->fnode->nb);
	// 	printf("stacka: %d, cost: %d, isupper: %d, index: %d\n", stack_a->nb, stack_a->cost, stack_a->isupper, stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// while(stack_b)
	// {
	// 	// printf("stackb: %d\n", stack_b->nb);
	// 	printf("\nstackb: %d, pair: %d, cost: %d, isupper: %d, index: %d, fcosts: %d, smode: %d", stack_b->nb, stack_b->fnode->nb, stack_b->cost, stack_b->isupper, stack_b->index, stack_b->fcosts, stack_b->smode);
	// 	stack_b = stack_b->next;
	// }
}

