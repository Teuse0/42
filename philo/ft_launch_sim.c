/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_sim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:29:12 by broy              #+#    #+#             */
/*   Updated: 2022/08/25 21:29:14 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_philo_eating(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->right_fork]));
	ft_action(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->left_fork]));
	ft_action(rules, philo->id, "has taken a fork");
	ft_action(rules, philo->id, "is eating");
	pthread_mutex_lock(&(philo->mutex_meal));
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&(philo->mutex_meal));
	ft_sleep(rules->eat_time, rules);
	pthread_mutex_lock(&(philo->mutex_ate));
	philo->ate = philo->ate + 1;
	pthread_mutex_unlock(&(philo->mutex_ate));
	pthread_mutex_unlock(&(rules->forks[philo->left_fork]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork]));
}

static void	ft_exit(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_destroy(&(rules->forks[i]));
		pthread_mutex_destroy(&(rules->philo[i].mutex_meal));
		pthread_mutex_destroy(&(rules->philo[i].mutex_ate));
		pthread_mutex_destroy(&(rules->philo[i].mutex_death));
		i++;
	}
	pthread_mutex_destroy(&(rules->writing));
	pthread_mutex_destroy(&(rules->mutex_ate));
}

static void	ft_death_check(t_rules *rules, t_philo *phi)
{
	int	i;

	while (!(rules->ate_all))
	{
		i = -1;
		while (++i < rules->nb_philo && !is_dead(rules))
		{
			pthread_mutex_lock(&(phi[i].mutex_meal));
			if (ft_time_diff(phi[i].last_meal, ft_time()) > rules->death_time)
				ft_dead(rules, i);
			pthread_mutex_unlock(&(phi[i].mutex_meal));
			usleep(100);
		}
		if (is_dead(rules))
			break ;
		i = 0;
		pthread_mutex_lock(&(rules->mutex_ate));
		while (rules->eat_nbr != -1 && i < rules->nb_philo
			&& is_eating(&phi[i]) >= rules->eat_nbr)
			i++;
		if (i == rules->nb_philo)
			rules->ate_all = 1;
		pthread_mutex_unlock(&(rules->mutex_ate));
	}
}

static void	*ft_thread(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_rules	*rules;

	i = 0;
	philo = (t_philo *)void_philo;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(1000);
	while (!is_dead(rules))
	{
		pthread_mutex_lock(&(rules->mutex_ate));
		if (rules->ate_all)
		{
			pthread_mutex_unlock(&(rules->mutex_ate));
			break ;
		}
		pthread_mutex_unlock(&(rules->mutex_ate));
		ft_philo_eating(philo);
		ft_action(rules, philo->id, "is sleeping");
		ft_sleep(rules->sleep_time, rules);
		ft_action(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

int	ft_philo(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = rules->philo;
	rules->first_time = ft_time();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, ft_thread, &(philo[i])))
			return (1);
		pthread_mutex_lock(&(philo[i].mutex_meal));
		philo[i].last_meal = ft_time();
		pthread_mutex_unlock(&(philo[i].mutex_meal));
		i++;
	}
	ft_death_check(rules, rules->philo);
	ft_exit(rules, philo);
	return (0);
}
