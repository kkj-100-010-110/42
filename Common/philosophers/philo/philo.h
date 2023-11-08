/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:46:54 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/08 01:16:39 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647

typedef enum e_status
{
	HUNGRY,
	EATING,
	SLEEPING,
	THINKING,
}	t_status;

typedef struct s_params
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_each_must_eat;
	unsigned char	progress_flag;
	unsigned char	must_eat_flag;
	struct timeval	init_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	progress;
	struct s_philo	*philo;
}	t_params;

typedef struct s_philo
{
	int				id;
	struct timeval	*init_time;
	struct timeval	last_meal;
	int				eat_count;
	t_params		*params;
	pthread_t		philo_thread;
	pthread_mutex_t	mealtime;
	pthread_mutex_t	full;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
}	t_philo;

void				free_malloc(t_params *params);
int					free_destroy(t_params *params,
						int fork_idx, int full_idx, int mealtime_idx);

int					initialize_params(int argc, char **argv, t_params *params);
int					init_malloc_vars(t_params *params);
int					init_mutex_vars(t_params *params);
int					init_philo_mutex(t_params *params);
void				init_philo(t_params *params);

int					start_philo(t_params *params);
void				*routine(void *philo_ptr);
void				when_one_philo(t_philo *philo);
int					join(t_params *params);

int					pickup(t_philo *philo);
int					eat(t_philo *philo);
void				putdown(t_philo *philo);
int					asleep(t_philo *philo);
int					think(t_philo *philo);

unsigned long long	diff_time(struct timeval early, struct timeval late);
unsigned long long	get_time(struct timeval tv);
unsigned long long	get_cur_time(void);
void				get_sleep_time(unsigned long long time);

unsigned int		check_progress(t_params *params);
unsigned int		check_full(t_params *params);
void				print_dead(t_params *params, int i);
unsigned int		check_dead(t_params *params);
void				monitoring(t_params *params);

int					get_int_arg(char *s);

void				print_status(t_philo *philo, t_status status);

#endif
