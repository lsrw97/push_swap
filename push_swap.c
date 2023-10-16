// we split the first argument into seperate strings with ft_split
// each string will be converted into a number with ft_atoi and stored in a int array
// we need an index variable to store the height of the stacks



#include <stdio.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

t_stack	*createstack(char **arr, int size)
{
	t_stack *stack;
	t_stack *tmp;
	char	**split;
	int		i;

	i = -1;
	if (size == 0)
		return (NULL);
	split = ft_split(concatargs(arr, size), ' ');
	if (!checkfornan(split) || !checkforinteger(split))
		return (NULL);
	size = arglen(split);
	stack = ft_newnode(ft_atoi(split[--size]), NULL);
	tmp = stack;
	while (--size >= 0)
	{
		tmp->next = ft_newnode(ft_atoi(split[size]), tmp);
		tmp = tmp->next;
	}
	if (!checkfordoubles(stack))
		return (NULL);
	return (stack);
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
		return (0);

	while (*(&stack_a->next->next->next))
		pb(&stack_a, &stack_b);
	sortthree(&stack_a);
	while (stack_b)
	{
		setpairs(&stack_a, &stack_b);
		setuppercostnode(&stack_b);
		setuppercostnode(&stack_a);
		node = findcheapest(&stack_b);
		sortmodesep(&stack_a, &stack_b, node);
		updateindex(&stack_a);
		updateindex(&stack_b);
	}
	getsmallestnbtotop(&stack_a, smallestindex(&stack_a));
}
