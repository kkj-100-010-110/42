/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:46:18 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/07 12:51:59 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_params(int argc, char **argv, t_params *params)
{
	params->num_of_philos = get_int_arg(argv[1]);
	params->time_to_die = get_int_arg(argv[2]);
	params->time_to_eat = get_int_arg(argv[3]);
	params->time_to_sleep = get_int_arg(argv[4]);
	params->progress_flag = TRUE;
	if (params->num_of_philos <= 0 || params->time_to_die < 0
		|| params->time_to_eat < 0 || params->time_to_sleep < 0)
		return (FALSE);
	if (argc == 6)
	{
		params->must_eat_flag = TRUE;
		params->time_each_must_eat = get_int_arg(argv[5]);
		if (params->time_each_must_eat <= 0)
			return (FALSE);
	}
	gettimeofday(&params->init_time, NULL);
	if (init_malloc_vars(params) == FALSE)
		return (FALSE);
	if (init_mutex_vars(params) == FALSE)
		return (FALSE);
	init_philo(params);
	return (TRUE);
}

int	init_malloc_vars(t_params *params)
{
	params->forks = malloc(sizeof(pthread_mutex_t) * params->num_of_philos);
	if (!(params->forks))
		return (FALSE);
	params->philo = malloc(sizeof(t_philo) * params->num_of_philos);
	if (!(params->philo))
	{
		free(params->forks);
		return (FALSE);
	}
	return (TRUE);
}

int	init_mutex_vars(t_params *params)
{
	if (init_philo_mutex(params) == FALSE)
		return (FALSE);
	if (pthread_mutex_init(&(params->progress), NULL))
	{
		free_destroy(params, params->num_of_philos - 1,
			params->num_of_philos - 1, params->num_of_philos - 1);
		return (FALSE);
	}
	return (TRUE);
}

int	init_philo_mutex(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_of_philos)
	{
		if (pthread_mutex_init(&(params->forks[i]), NULL))
		{
			free_destroy(params, i - 1, i - 1, i - 1);
			return (FALSE);
		}
		if (pthread_mutex_init(&(params->philo[i].mealtime), NULL))
		{
			free_destroy(params, i, i - 1, i - 1);
			return (FALSE);
		}
		if (pthread_mutex_init(&(params->philo[i].full), NULL))
		{
			free_destroy(params, i, i, i - 1);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	init_philo(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_of_philos)
	{
		params->philo[i].id = i + 1;
		params->philo[i].init_time = &(params->init_time);
		params->philo[i].last_meal = params->init_time;
		params->philo[i].eat_count = 0;
		params->philo[i].params = params;
		params->philo[i].lfork = &(params->forks[i]);
		params->philo[i].rfork = &(params->forks[\
				(i + (params->num_of_philos - 1)) % params->num_of_philos]);
		i++;
	}
}
