/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:32:18 by broy              #+#    #+#             */
/*   Updated: 2022/08/24 17:57:58 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_mutex(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->mutex_dead), NULL))
		return (1);
	return (0);
}

static void	ft_init_philo(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].ate = 0;
		rules->philo[i].left_fork = i;
		rules->philo[i].right_fork = (i + 1) % rules->nb_philo;
		rules->philo[i].last_meal = 0;
		rules->philo[i].rules = rules;
		pthread_mutex_init(&(rules->philo[i].mutex_meal), NULL);
		pthread_mutex_init(&(rules->philo[i].mutex_death), NULL);
		pthread_mutex_init(&(rules->philo[i].mutex_ate), NULL);
	}
	pthread_mutex_init(&(rules->mutex_ate), NULL);
}

static int	ft_init(t_rules *rules, char **av)
{
	rules->nb_philo = ft_atoi(av[1]);
	rules->death_time = ft_atoi(av[2]);
	rules->eat_time = ft_atoi(av[3]);
	rules->sleep_time = ft_atoi(av[4]);
	rules->ate_all = 0;
	rules->dead = 0;
	if (rules->nb_philo < 1 || rules->death_time < 0 || rules->eat_time < 0
		|| rules->sleep_time < 0 || rules->nb_philo > 250)
		return (1);
	if (av[5])
	{
		rules->eat_nbr = ft_atoi(av[5]);
		if (rules->eat_nbr <= 0)
			return (1);
	}
	else
		rules->eat_nbr = -1;
	if (ft_init_mutex(rules))
		return (2);
	ft_init_philo(rules);
	if (rules->nb_philo == 1)
		if (ft_one_philo(rules))
			return (3);
	return (0);
}

static void	ft_error(int ret)
{
	if (ret == 1)
		printf("Wrong arguments\n");
	if (ret == 2)
		printf("Mutex error\n");
	if (ret == 3)
		printf("Thread error\n");
	if (ret == 4)
		printf("Wrong number of arguments\n");
}

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ft_check_args(av) || (ac != 5 && ac != 6))
	{
		if (ac != 5 && ac != 6)
			ft_error(4);
		if (ft_check_args(av))
			ft_error(1);
		return (1);
	}
	if (ft_init(&rules, av) != 0)
	{
		ft_error(ft_init(&rules, av));
		return (1);
	}
	if (rules.nb_philo != 1)
	{
		if (ft_philo(&rules))
		{
			ft_error(3);
			return (1);
		}
	}
	return (0);
}
