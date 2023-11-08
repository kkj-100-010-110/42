/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:46:30 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/06 23:02:45 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_malloc(t_params *params)
{
	if (params->forks != NULL)
	{
		free(params->forks);
		params->forks = NULL;
	}
	if (params->philo != NULL)
	{
		free(params->philo);
		params->philo = NULL;
	}
}

int	free_destroy(t_params *params, int fork_idx, int full_idx, int mealtime_idx)
{
	int	idx;

	pthread_mutex_destroy(&(params->progress));
	idx = 0;
	while (idx <= fork_idx)
	{
		pthread_mutex_destroy(&params->forks[idx]);
		idx++;
	}
	idx = 0;
	while (idx <= full_idx)
	{
		pthread_mutex_destroy(&(params->philo[idx].full));
		idx++;
	}
	idx = 0;
	while (idx <= mealtime_idx)
	{
		pthread_mutex_destroy(&(params->philo[idx]).mealtime);
		idx++;
	}
	free_malloc(params);
	return (TRUE);
}
