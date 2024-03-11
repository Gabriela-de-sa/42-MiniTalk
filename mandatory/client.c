/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:08 by gabriela          #+#    #+#             */
/*   Updated: 2024/03/09 16:33:01 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "../libft/libft.h"
#include <stdio.h>

void	send_bit(int pid, char byte)
{
	unsigned char	temp;
	int				i_bit;

	i_bit = 8;
	temp = (unsigned char) byte;
	while (i_bit--)
	{
		temp = (byte >> i_bit);
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit(pid, str[i]);
		i++;
	}
}

void	receive_signal(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		;
	else
		exit(ft_printf("Error - Signal received with problem."));
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &receive_signal;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal."));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal."));
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	ft_check_args(argc, argv);
	sig_handler();
	send_message(pid, argv[2]);
	send_message(pid, "\n");
}
