/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:46:48 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/07 23:43:25 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pickup(t_philo *philo)
{
	pthread_mutex_lock(&(philo->params->progress));
	if (philo->params->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&(philo->params->progress));
		return (FALSE);
	}
	pthread_mutex_unlock(&(philo->params->progress));
	pthread_mutex_lock(philo->lfork);
	print_status(philo, HUNGRY);
	pthread_mutex_lock(philo->rfork);
	print_status(philo, HUNGRY);
	return (TRUE);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->params->progress));
	if (philo->params->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&(philo->params->progress));
		putdown(philo);
		return (FALSE);
	}
	pthread_mutex_unlock(&(philo->params->progress));
	pthread_mutex_lock(&(philo->mealtime));
	gettimeofday(&(philo->last_meal), NULL);
	print_status(philo, EATING);
	pthread_mutex_unlock(&(philo->mealtime));
	pthread_mutex_lock(&(philo->full));
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->full));
	get_sleep_time(philo->params->time_to_eat);
	return (TRUE);
}

void	putdown(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

int	asleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->params->progress));
	if (philo->params->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&(philo->params->progress));
		return (FALSE);
	}
	pthread_mutex_unlock(&(philo->params->progress));
	print_status(philo, SLEEPING);
	get_sleep_time(philo->params->time_to_sleep);
	return (TRUE);
}

int	think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->params->progress));
	if (philo->params->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&(philo->params->progress));
		return (FALSE);
	}
	pthread_mutex_unlock(&(philo->params->progress));
	print_status(philo, THINKING);
	return (TRUE);
}
