/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:48:11 by terussar          #+#    #+#             */
/*   Updated: 2023/09/08 15:17:10 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	parsing(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| ft_atoi(av[4]) < 0)
		return (1);
	if (ft_strncmp(ft_itoa(ft_atoi(av[1])), av[1], ft_strlen(av[1])) != 0)
		return (1);
	if (ft_strncmp(ft_itoa(ft_atoi(av[2])), av[2], ft_strlen(av[2])) != 0)
		return (1);
	if (ft_strncmp(ft_itoa(ft_atoi(av[3])), av[3], ft_strlen(av[3])) != 0)
		return (1);
	if (ft_strncmp(ft_itoa(ft_atoi(av[4])), av[4], ft_strlen(av[4])) != 0)
		return (1);
	if (ac == 6)
	{
		if (ft_atoi(av[4]) < 0 || ft_strncmp(ft_itoa(ft_atoi(av[5])), av[5], ft_strlen(av[5])) != 0)
		return (1);
	}
	return (0);
}
