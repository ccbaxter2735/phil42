#include "../includes/philosopher.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strerror(char *str)
{
	write (2, str, ft_strlen(str));
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result <= 0)
	{
		ft_strerror("error\ninput must be positive\n");
		return (-1);
	}
	return (result);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = '\0';
		i++;
	}
}