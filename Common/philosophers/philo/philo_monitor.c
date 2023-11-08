/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:14:06 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/07 12:36:11 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	check_progress(t_params *params)
{
	pthread_mutex_lock(&(params->progress));
	if (params->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&(params->progress));
		return (TRUE);
	}
	pthread_mutex_unlock(&(params->progress));
	return (FALSE);
}

unsigned int	check_full(t_params *params)
{
	int	i;
	int	ok_philo_count;

	if (check_progress(params))
		return (TRUE);
	i = 0;
	ok_philo_count = 0;
	while (i < params->num_of_philos)
	{
		pthread_mutex_lock(&(params->philo[i].full));
		if (params->philo[i].eat_count >= params->time_each_must_eat)
			ok_philo_count++;
		pthread_mutex_unlock(&(params->philo[i].full));
		i++;
	}
	if (ok_philo_count == params->num_of_philos)
	{
		pthread_mutex_lock(&(params->progress));
		params->progress_flag = FALSE;
		pthread_mutex_unlock(&(params->progress));
		printf("All philosophers are full.\n");
		return (TRUE);
	}
	return (FALSE);
}

void	print_dead(t_params *params, int i)
{
	struct timeval	cur_time;

	pthread_mutex_lock(&(params->progress));
	gettimeofday(&cur_time, NULL);
	printf("%llums %d %s\n", diff_time(params->init_time, cur_time),
		params->philo[i].id, "died");
	params->progress_flag = FALSE;
	pthread_mutex_unlock(&(params->progress));
}

unsigned int	check_dead(t_params *params)
{
	int				i;
	struct timeval	cur_time;

	if (check_progress(params))
		return (TRUE);
	i = 0;
	while (i < params->num_of_philos)
	{
		pthread_mutex_lock(&(params->philo[i].mealtime));
		gettimeofday(&cur_time, NULL);
		if (diff_time(params->philo[i].last_meal, cur_time)
			> (unsigned long long)params->time_to_die)
		{
			pthread_mutex_unlock(&(params->philo[i].mealtime));
			print_dead(params, i);
			return (TRUE);
		}
		pthread_mutex_unlock(&(params->philo[i].mealtime));
		i++;
	}
	return (FALSE);
}

void	monitoring(t_params *params)
{
	if (params->must_eat_flag)
	{
		while (TRUE)
		{
			if (check_full(params))
				break ;
			if (check_dead(params))
				break ;
			usleep(100);
		}
	}
	else
	{
		while (TRUE)
		{
			if (check_dead(params))
				break ;
			usleep(100);
		}
	}
}
