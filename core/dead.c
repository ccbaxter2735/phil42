/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccbaxter <ccbaxter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:04:30 by terussar          #+#    #+#             */
/*   Updated: 2023/09/07 21:37:54 by ccbaxter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	is_dead(t_philo	*philo)
{
	philo->time = ft_time() - philo->start_time;
	if (philo->r_philo->end_b == 1)
		return (1);
	if ((philo->time - philo->last_time_eat) < philo->r_philo->time_to_die)
		return (0);
	else
	{
		pthread_mutex_lock(&philo->r_philo->end);
		philo->r_philo->end_b = 1;
		pthread_mutex_unlock(&philo->r_philo->end);
		take_time_and_str(philo, "is dead");
		return (1);
	}
}