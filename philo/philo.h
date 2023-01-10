/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:36:47 by broy              #+#    #+#             */
/*   Updated: 2022/10/25 17:59:31 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

struct	s_rules;

typedef struct s_philo
{
	int					id;
	int					ate;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	pthread_mutex_t		mutex_meal;
	pthread_mutex_t		mutex_ate;
	pthread_mutex_t		mutex_death;
	pthread_t			thread_id;
	struct s_rules		*rules;
}t_philo;

typedef struct s_rules
{
	int				nb_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nbr;
	int				dead;
	int				ate_all;
	long long		first_time;

	pthread_mutex_t	mutex_ate;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	writing;
	t_philo			philo[250];
}t_rules;

int			ft_philo(t_rules *rules);
long long	ft_time_diff(long long prev, long long cur);
long long	ft_time(void);
int			ft_atoi(char *str);
void		ft_action(t_rules *rules, int id, char *str);
void		ft_sleep(long long time, t_rules *rules);
int			is_dead(t_rules *rules);
int			is_eating(t_philo *philo);
int			ft_one_philo(t_rules *rules);
void		ft_dead(t_rules *rules, int i);
int			ft_check_args(char **av);

#endif
