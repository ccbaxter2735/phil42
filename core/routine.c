#include "../includes/philosopher.h"

void	*threading(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	if ((philo->id % 2 == 0 && philo->r_philo->nb_philo % 2 == 1)
		|| (philo->r_philo->nb_philo % 2 == 1 && philo->id % 2 == 0)
		|| (philo->r_philo->nb_philo % 2 == 1 && philo->id == philo->r_philo->nb_philo))
		ft_usleep(philo, 10);
	while (is_dead(philo) == 0)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (philo->r_philo->nb_philo_x_eat == philo->r_philo->nb_philo)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	return (NULL);
}