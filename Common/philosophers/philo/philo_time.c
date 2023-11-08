/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:34:44 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/07 12:40:21 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	diff_time(struct timeval early, struct timeval late)
{
	unsigned long long	time;

	time = (late.tv_sec * 1000 - early.tv_sec * 1000);
	time += ((late.tv_usec / 1000) - (early.tv_usec / 1000));
	return (time);
}

unsigned long long	get_time(struct timeval tv)
{
	unsigned long long	time;

	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}

unsigned long long	get_cur_time(void)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	return (get_time(cur_time));
}

void	get_sleep_time(unsigned long long time)
{
	unsigned long long	end;

	end = get_cur_time() + time;
	while (get_cur_time() <= end)
		usleep(100);
}
