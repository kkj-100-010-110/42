/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:54 by gyeokim           #+#    #+#             */
/*   Updated: 2022/09/08 01:08:19 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	memset(&params, 0, sizeof(t_params));
	if (initialize_params(argc, argv, &params) == FALSE)
	{
		printf("Error on initialization.\n");
		exit(EXIT_FAILURE);
	}
	if (start_philo(&params) == FALSE)
	{
		printf("Error on working.\n");
		exit(EXIT_FAILURE);
	}
	monitoring(&params);
	join(&params);
	free_destroy(&params, params.num_of_philos - 1, \
			params.num_of_philos - 1, params.num_of_philos - 1);
	return (0);
}
