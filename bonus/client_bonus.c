/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:39:57 by gabriela          #+#    #+#             */
/*   Updated: 2024/03/12 22:14:42 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/minitalk_bonus.h"
#include "../libft/libft.h"

static int	g_send_bit;

void	send_signal(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		g_send_bit = 1;
    write(1, "SIGNAL RECEIVED FROM SERVER\n", 29);
}

void	send_bit(int pid, char bit)
{
	unsigned char	temp;
	int				i_bit;

	i_bit = 8;
	temp = (unsigned char) bit;
	while (i_bit--)
	{
		g_send_bit = 0;
		temp = (bit >> i_bit);
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_send_bit)
			;
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

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &send_signal;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal."));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal."));
}

int	main(int argc, char **argv)
{
	int	pid;

	ft_check_args(argc, argv);
	pid = atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	sig_handler();
	if (argv[2][0] == '\0')
		send_message(pid, "\0");
	send_message(pid, argv[2]);
	send_message(pid, "\n");
	return (0);
}
