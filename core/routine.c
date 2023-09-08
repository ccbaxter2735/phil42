#include "../includes/philosopher.h"

void	*threading(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	if ((philo->id % 2 == 0 && philo->r_philo->nb_philo % 2 == 0)
		|| (philo->r_philo->nb_philo % 2 == 1
		&& (philo->id == philo->r_philo->nb_philo || philo->id == philo->r_philo->nb_philo)))
		ft_think(philo);
	while (is_dead(philo) == 0)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (philo->nb_meal == 0)
		{
			philo->r_philo->nb_philo_x_eat += 1;
			// printf("philo end = %d\n", philo->r_philo->nb_philo_x_eat);
			while (philo->r_philo->nb_philo_x_eat != philo->r_philo->nb_philo)
				ft_think(philo);
			break ;
		}
		if (ft_sleep(philo) != 0)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	return (NULL);
}