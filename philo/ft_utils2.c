/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:04 by broy              #+#    #+#             */
/*   Updated: 2022/10/25 16:50:06 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_rules *rules)
{
	int	i;

	pthread_mutex_lock(&(rules->mutex_dead));
	i = rules->dead;
	pthread_mutex_unlock(&(rules->mutex_dead));
	return (i);
}

int	is_eating(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&(philo->mutex_ate));
	i = philo->ate;
	pthread_mutex_unlock(&(philo->mutex_ate));
	return (i);
}

static void	*ft_thread_one(void *void_philo)
{
	t_rules	*rules;
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	ft_action(rules, philo->id, "has taken a fork");
	printf("%lld 1 is dead\n",
		rules->death_time + ft_time() - rules->first_time);
	return (NULL);
}

int	ft_one_philo(t_rules *rules)
{
	t_philo	*philo;

	philo = rules->philo;
	rules->first_time = ft_time();
	if (pthread_create(&(philo[0].thread_id), NULL, ft_thread_one, &(philo[0])))
		return (1);
	pthread_join(philo[0].thread_id, NULL);
	return (0);
}

void	ft_dead(t_rules *rules, int i)
{
	ft_action(rules, i, "died");
	pthread_mutex_lock(&(rules->mutex_dead));
	rules->dead = 1;
	pthread_mutex_unlock(&(rules->mutex_dead));
}
