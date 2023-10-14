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
	int		*pos;

	stack_a = createstack(args, argc);
	stack_b = NULL;
	if (!stack_a)
		return 0;

while(*(&stack_a))
{
	getsmallestnbtotop(&stack_a, smallestindex(&stack_a));
	pb(&stack_a, &stack_b);
}
while(*(&stack_b))
	pa(&stack_a, &stack_b);


	// while(stack_a)
	// {
	// 	printf("stacka: %d\n", stack_a->nb);
	// 	stack_a = stack_a->next;
	// }
	// while(stack_b)
	// {
	// 	printf("\nstackb: %d", stack_b->nb);
	// 	stack_b = stack_b->next;
	// }

	
	// char	**split;
	// int 	i = -1;

	// split = NULL;
	// split = ft_split(concatargs(args, argc), ' ');
	// // printf("%d\n\n", checkfornan(concatargs(args, argc)));
	
	// // while(split[++i])
	// // 	printf("split: %s\n", split[i]);
	// t_stack *stack = createstack(split, arglen(split));
	

	// sa(&stack);
// while(stack)
// 	{
// 		printf("\nstackb: %d", stack->nb);
// 		stack = stack->next;
// 	}

	// printf("checkdoubles: %d\n", checkforinteger(sp lit));
}
