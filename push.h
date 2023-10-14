
#ifndef PUSH_H
# define PUSH_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_stack
{
	int             nb;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

t_stack	*ft_newnode(int nb, t_stack *prev);
void	ft_nodeadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_nodelast(t_stack *lst);
void	ft_nodeiter(t_stack *lst, void (*f)(int));
t_stack	*ft_nodelast(t_stack *lst);
void	ft_nodeitermod(t_stack *lst, void (*f)(t_stack*, t_stack*));
void	sa(t_stack **stack);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	pb(t_stack **stacka, t_stack **stackb);
void	push(t_stack **stack, t_stack *node);
int	ft_nodesize(t_stack *lst);
void	pa(t_stack **stacka, t_stack **stackb);
t_stack	*getfirstnode(t_stack *stack);
int	biggestindex(t_stack **stack);
void	getBiggestNbToTop(t_stack **stack, int index);
char	*concatargs(char **args, int argc);
int	checkfornan(char **str);
int	arglen(char **args);
int checkfordoubles(t_stack *stack);
int	checkforinteger(char **split);
int	smallestindex(t_stack **stack);
void	getsmallestnbtotop(t_stack **stack, int index);


#endif
