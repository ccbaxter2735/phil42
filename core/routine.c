#include "../includes/philosopher.h"

void	*threading(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	if (philo->r_philo->nb_philo == 1)
	{
		ft_usleep(philo, 1);
		take_time_and_str(philo, "is dead");
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo, 10);
	while (is_dead(philo) == 0)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (philo->r_philo->nb_philo_x_eat == philo->r_philo->nb_philo)
		{
			take_time_and_str(philo, "is thinking");
			break ;
		}
		if (ft_sleep(philo) != 0)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	printf("test routine\n");
	return (NULL);
}