#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push.h"

int	arglen(char **args)
{
	int	i;

	i = 0;
	while(args[i])
		i++;
	return (i);
}

long long	ft_atoi_mod(const char *nptr)
{
	int				i;
	long long		num;
	int				n;

	i = 0;
	num = 0;
	n = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			n = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return ((num *= n));
}

int	checkfornan(char **str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while(str[++j])
	{
		while(str[j][++i])
		{
			if ((str[j][i] != 32 && str[j][i] != 0) && (str[j][i] < 47 || str[j][i] > 57))
			{
				if(str[j][i] != '-' && (str[j][i + 1] > 47 && str[j][i + 1] < 57))
					{ft_printf("ERRORNAN\n%d", str[j][i]);
					return 0;}
			}
		}
		i = -1;
	}
	return 1;
}

int checkfordoubles(t_stack *stack)
{
	t_stack	*stack2;

	stack2 = stack;
	stack = stack->next;
	while (stack2->next)
	{
		while(stack)
		{
			if(stack->nb == stack2->nb)
			{
				ft_printf("ERROR\n");
				return 0;
			}
			stack = stack->next;
		}
		stack2 = stack2->next;
		stack = stack2->next;
	}
	return (1);
}

int	checkforinteger(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (ft_atoi_mod(split[i]) > 2147483647 || ft_atoi_mod(split[i]) < -2147483648)
		{
			ft_printf("ERROR\n");
			return 0;
		}
	}
	return (1);
} 
