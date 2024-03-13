/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:03:52 by gabriela          #+#    #+#             */
/*   Updated: 2024/03/12 21:56:05 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/minitalk_bonus.h"
#include "../libft/libft.h"

int	g_received_bit = 0;

void	receive_message(int signal, siginfo_t *siginfo, void *context)
{
	static unsigned char	buff;

	(void) context;
	if (signal == SIGUSR1)
		buff |= 1;
	g_received_bit++;
	if (g_received_bit == 8)
	{
		write(1, &buff, 1);
		g_received_bit = 0;
		buff = 0;
	}
	else
		buff = buff << 1;
	if (signal == SIGUSR1)
		kill(siginfo->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(siginfo->si_pid, SIGUSR2);
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &receive_message;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal."));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal."));
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %i\n\n", pid);
	sig_handler();
	while (1)
		pause();
	return (0);
}
