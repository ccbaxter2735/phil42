/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccbaxter <ccbaxter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:48:33 by terussar          #+#    #+#             */
/*   Updated: 2023/09/20 03:56:03 by ccbaxter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	initialize_arg(t_data *data, char **av, int ac)
{
	data->rules.nb_philo = ft_atoi(av[1]);
	data->rules.time_to_die = ft_atoi(av[2]);
	data->rules.time_to_eat = ft_atoi(av[3]);
	data->rules.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->rules.nb_x_eat = ft_atoi(av[5]);
	else
		data->rules.nb_x_eat = -1;
}

int	ft_malloc_thread(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->rules.nb_philo);
	if (!data->philo)
		return (1);
	data->th_id = malloc(sizeof(pthread_t) * data->rules.nb_philo);
	if (!data->th_id)
		return (1);
	ft_bzero(data->th_id, (sizeof(pthread_t) * data->rules.nb_philo));
	ft_bzero(data->philo, (sizeof(t_philo) * data->rules.nb_philo));
	return (0);
}

int	initialize_thread(t_data *data)
{
	int		i;
	// long	tmp;

	i = 0;
	if (ft_malloc_thread(data) == 1)
		return (1);
	pthread_mutex_init(&(data->rules.write), NULL);
	pthread_mutex_init(&(data->rules.end), NULL);
	data->rules.nb_philo_x_eat = 0;
	while (i < data->rules.nb_philo)
	{
		data->philo[i].nb_meal = data->rules.nb_x_eat;
		data->philo[i].id = i + 1;
		data->philo[i].r_philo = &data->rules;
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		i++;
	}
	i = 0;
	data->rules.start_time = ft_time();
	while (i < data->rules.nb_philo)
	{
		if (i == data->rules.nb_philo - 1)
			data->philo[i].fork_r = &data->philo[0].fork_l;
		else
			data->philo[i].fork_r = &data->philo[i + 1].fork_l;
		if (pthread_create(&data->th_id[i], NULL,
				threading, &data->philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < data->rules.nb_philo)
	{
		if (pthread_join(data->th_id[i], NULL) != 0)
			ft_strerror("error\nfailed to join thread\n");
		pthread_mutex_destroy(&data->philo[i].fork_l);
		pthread_mutex_destroy(data->philo[i].fork_r);
		i++;
	}
	pthread_mutex_destroy(&data->rules.write);
	pthread_mutex_destroy(&data->rules.end);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (parsing(ac, av) == 0)
	{
		initialize_arg(&data, av, ac);
		if (initialize_thread(&data))
		{

			return (1);
		}
	}
	else
		ft_strerror("Error\nwrong number of arguments or non-unsigned integer\n");
	free(data.philo);
	free(data.th_id);
	return (0);
}