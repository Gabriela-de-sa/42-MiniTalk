/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:12 by gabriela          #+#    #+#             */
/*   Updated: 2024/03/07 12:50:26 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "../libft/libft.h"
#include <signal.h>

void	receive_message(int sig, siginfo_t *siginfo, void *ucontext)
{
	// vai receber a mensagem do cliente
	(void)	sig;
    (void)	ucontext;

	ft_printf("\tsi_pid..: %d\n", siginfo->si_pid);
	ft_printf("recebi mensagem do cliente\n");
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &receive_message;
	sa.sa_flags = SA_SIGINFO;
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
	while (1)
		sig_handler();
}
