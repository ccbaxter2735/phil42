#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_rules
{
	int							nb_philo;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							nb_x_eat; //option
	int							nb_philo_x_eat;
	int							end_b;//
	pthread_mutex_t				write;
	pthread_mutex_t				end;
}	t_rules;

typedef	struct	s_philo
{
	int	id;
	int	nb_meal;
	int	tab_fork[2];
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
	long	start_time;
	long	last_time_eat;
	long	time;
	t_rules *r_philo;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo *philo;
	pthread_t *th_id;
	t_rules rules;
	// pthread_mutex_t	*mutex_id;
} t_data;

int   ft_strlen(char *str);
void	ft_strerror(char *str);
int   ft_atoi(char *str);
void  ft_bzero(void *str, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int nb);
void	free_array(char **tab);
int		parsing(int ac, char **av);


long	ft_time();
int		is_dead(t_philo	*philo);
void	take_time_and_str(t_philo *philo, char *str);
int		ft_eat(t_philo *philo1);
int		ft_sleep(t_philo *philo1);
int		ft_think(t_philo *philo1);
void	ft_usleep(t_philo *philo, long time);

void	*threading(void *arg);

void	define_fork(t_philo *philo);

#endif