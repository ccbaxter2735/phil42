/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccbaxter <ccbaxter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:50:52 by terussar          #+#    #+#             */
/*   Updated: 2023/09/15 23:56:18 by ccbaxter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

long	ft_time()
{
	struct	timeval	current_time;
	long			time_ms;

	if(gettimeofday (&current_time, NULL) == -1)
	{
		ft_strerror("error\ngettimeofday returned -1\n");
		return (-1);
	}
	time_ms = (current_time.tv_usec / 1000) + (current_time.tv_sec * 1000);
	return (time_ms);
}

void	take_time_and_str(t_philo *philo, char *str)
{
	long	time;

	time = -1;
	time = ft_time() - philo->r_philo->start_time;
	if (time > 0)
	{
		pthread_mutex_lock(&philo->r_philo->write);
		printf("%ld %d %s\n", time, philo->id, str);
		pthread_mutex_unlock(&philo->r_philo->write);
	}
}

int	ft_eat(t_philo *philo1)
{
	if (is_dead(philo1) == 0)
	{
		pthread_mutex_lock(&(philo1->fork_l));
		take_time_and_str(philo1, "has take a fork");
		pthread_mutex_lock(philo1->fork_r);
		take_time_and_str(philo1, "has take a fork");
		take_time_and_str(philo1, "is eating");
		ft_usleep(philo1, philo1->r_philo->time_to_eat);
		pthread_mutex_unlock(&(philo1->fork_l));
		pthread_mutex_unlock(philo1->fork_r);
		philo1->last_time_eat = ft_time();
		if (philo1->nb_meal != -1)
		{
			philo1->nb_meal--;
			if (philo1->nb_meal == 0)
			{
				philo1->r_philo->nb_philo_x_eat++;
				take_time_and_str(philo1, "is thinking");
				ft_usleep(philo1, 10000);
			}
		}
		return (0);
	}
	return (1);
}

int	ft_sleep(t_philo *philo1)
{
	if (is_dead(philo1) == 0)
	{
		take_time_and_str(philo1, "is sleeping");
		ft_usleep(philo1, philo1->r_philo->time_to_sleep);
		return (0);
	}
	return (1);
}

int	ft_think(t_philo *philo1)
{
	int time_think;
	
	if (philo1->r_philo->time_to_eat >= philo1->r_philo->time_to_sleep)
    	time_think = (philo1->r_philo->time_to_eat - philo1->r_philo->time_to_sleep);
	else
		time_think = 0;
	if (is_dead(philo1) == 0)
	{
		take_time_and_str(philo1, "is thinking");
		ft_usleep(philo1, time_think);
		return (0);
	}
	return (1);
}
