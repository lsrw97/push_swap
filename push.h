
#ifndef PUSH_H
# define PUSH_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_stack
{
	int             nb;
	int				id;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

t_stack	*ft_newnode(int nb, t_stack *prev);
void	ft_nodeadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_nodelast(t_stack *lst);
void	ft_nodeiter(t_stack *lst, void (*f)(int));
t_stack	*ft_nodelast(t_stack *lst);
void	ft_nodeitermod(t_stack *lst, void (*f)(t_stack*, t_stack*));
void sa(t_stack *stack);
void	ra(t_stack *stack);
void	rr(t_stack *stack);
int	pb(t_stack **stacka, t_stack **stackb);
int	ft_nodesize(t_stack *lst);
int	pa(t_stack **stackb, t_stack **stacka);

#endif
