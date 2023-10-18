/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:13:13 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/18 13:12:25 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_stack
{
	int				nb;
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

t_stack		*ft_newnode(int nb, t_stack *prev);
t_stack		*ft_nodelast(t_stack *lst);
t_stack		*ft_nodelast(t_stack *lst);
void		sa(t_stack **stack);
void		sb(t_stack **stack);
void		ra(t_stack **stack, int i);
void		rra(t_stack **stack, int i);
void		rb(t_stack **stack, int i);
void		rrb(t_stack **stack, int i);
void		rr(t_stack **stacka, t_stack **stackb);
void		rrr(t_stack **stacka, t_stack **stackb);
void		pb(t_stack **stacka, t_stack **stackb);
void		push(t_stack **stack, t_stack *node);
int			ft_nodesize(t_stack *lst);
void		pa(t_stack **stacka, t_stack **stackb);
t_stack		*getfirstnode(t_stack *stack);
int			biggestindex(t_stack **stack);
char		*concatargs(char **args, int argc);
int			checkfornan(char **str, char *str2);
int			arglen(char **args);
int			checkfordoubles(t_stack *stack);
int			checkforinteger(char **split, char *str);
int			smallestindex(t_stack **stack);
void		getsmallestnbtotop(t_stack **stack, int index);
int			friendscore(int num, int num2);
void		setpairs(t_stack **stack_a, t_stack **stack_b);
void		setuppercostnode(t_stack **stack);
void		sortthree(t_stack **stack);
t_stack		*findcheapest(t_stack **stack);
int			realcost(t_stack *nodea, t_stack *nodeb);
int			cheapestcost(int i, int j, int x, t_stack *node);
int			nodesizedown(t_stack *lst);
void		sortmodesep(t_stack **stacka, t_stack **stackb, t_stack *node);
void		updateindex(t_stack	**stack);
int			costmode(t_stack *nodea, t_stack *nodeb);
void		setfriendnode(t_stack *nodea, t_stack *nodeb);
int			min(t_stack *a, t_stack *b);
int			max(int i, int j);
int			mincost(int i, int j, int x);
int			detectpair(t_stack **stack_a, t_stack **stack_b, int diff);
void		freesplit(char **split);
void		freestack(t_stack *stack);
void		smallsort(t_stack **stack);
int			issorted(t_stack *stack);

#endif
