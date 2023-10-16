
#ifndef PUSH_H
# define PUSH_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_stack
{
	int             nb;
	int				cost;
	int				isupper;
	int				fscore;
	int				index;
	int				fcosts;
	int				smode;
	struct t_stack	*fnode;
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
void	ra(t_stack **stack, int i);
void	rra(t_stack **stack, int i);
void	rb(t_stack **stack, int i);
void	rrb(t_stack **stack, int i);
void	rr(t_stack **stacka, t_stack **stackb);
void	rrr(t_stack **stacka, t_stack **stackb);
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
int	friendscore(int num, int num2);
void	setpairs(t_stack **stack_a, t_stack **stack_b);
void	setuppercostnode(t_stack **stack);
void	sortthree(t_stack **stack);
t_stack	*findcheapest(t_stack **stack);
int realcost(t_stack *nodea, t_stack *nodeb);
int cheapestcost(int i, int j, int x, t_stack *node);
int	nodesizedown(t_stack *lst);
void	sortmodesep(t_stack **stacka, t_stack **stackb, t_stack *node);
void sortmodeup(t_stack **stacka, t_stack **stackb, t_stack *node);
void sortmodedown(t_stack **stacka, t_stack **stackb, t_stack *node);
void	updateindex(t_stack	**stack);
void	sortmode(int i, t_stack **stacka, t_stack **stackb, t_stack *node);
int	costmode(t_stack *nodea, t_stack *nodeb);

#endif
