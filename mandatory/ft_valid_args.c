/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:38:29 by gabriela          #+#    #+#             */
/*   Updated: 2024/03/12 14:25:27 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "../libft/libft.h"

void	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		exit(ft_printf("Error - Usage: ./client [server_pid] [message]\n"));
	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) == 0)
			exit(ft_printf("Error - Invalid PID"));
		i++;
	}
	if (argv[2] == 0)
		exit(ft_printf("Error - Invalid message."));
}
