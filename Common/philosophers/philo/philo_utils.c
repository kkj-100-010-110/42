/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:01:06 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/07 05:23:21 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_int_arg(char *s)
{
	long	result;

	result = 0;
	if (!s || *s == '-' || *s == '+')
		return (-1);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (-1);
		result = (result * 10) + (*s - '0');
		s++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result);
}

void	print_status(t_philo *philo, t_status status)
{
	struct timeval	cur_time;
	const char		*state[] = {"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};

	pthread_mutex_lock(&(philo->params->progress));
	if (philo->params->progress_flag == FALSE)
	{
		pthread_mutex_unlock(&(philo->params->progress));
		return ;
	}
	gettimeofday(&cur_time, NULL);
	printf("%llums %d %s\n", diff_time(*(philo->init_time), cur_time), philo->id,
		state[status]);
	pthread_mutex_unlock(&(philo->params->progress));
}
