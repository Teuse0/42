/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:13:54 by broy              #+#    #+#             */
/*   Updated: 2022/08/19 19:13:56 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

long long	ft_time_diff(long long prev, long long cur)
{
	return (cur - prev);
}

long long	ft_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = ft_time();
	while (!is_dead(rules))
	{
		if (ft_time_diff(i, ft_time()) >= time)
			break ;
		usleep(50);
	}
}

void	ft_action(t_rules *rules, int id, char *str)
{
	pthread_mutex_lock(&(rules->writing));
	if (!is_dead(rules))
	{
		printf("%lli ", ft_time() - rules->first_time);
		printf("%i ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(rules->writing));
}
