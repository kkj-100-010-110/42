/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:46:40 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/07 13:09:35 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philo(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_of_philos)
	{
		if (pthread_create(&(params->philo[i].philo_thread), NULL, \
					routine, (void *)&(params->philo[i])))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->params->num_of_philos == 1)
	{
		when_one_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(philo->params->time_to_eat / 2);
	while (TRUE)
	{
		if (pickup(philo) == FALSE)
			return (NULL);
		if (eat(philo) == FALSE)
			return (NULL);
		putdown(philo);
		if (asleep(philo) == FALSE)
			return (NULL);
		if (think(philo) == FALSE)
			return (NULL);
	}
}

void	when_one_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo->params->progress));
	if (philo->params->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&(philo->params->progress));
		return ;
	}
	pthread_mutex_unlock(&(philo->params->progress));
	pthread_mutex_lock(philo->lfork);
	print_status(philo, HUNGRY);
	pthread_mutex_unlock(philo->lfork);
	get_sleep_time(philo->params->time_to_die);
}

int	join(t_params *params)
{
	int		i;
	void	*ret;

	i = 0;
	ret = NULL;
	while (i < params->num_of_philos)
	{
		if (pthread_join(params->philo[i].philo_thread, &ret))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
