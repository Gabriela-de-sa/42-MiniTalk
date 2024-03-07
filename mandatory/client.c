/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:08 by gabriela          #+#    #+#             */
/*   Updated: 2024/03/07 14:33:02 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "../libft/libft.h"

// funcao para enviar a mensagem
void	send_message(int sig, char *str)
{
	
}

void	receive_signal(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
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
	int	sig;

	sig = atoi(argv[1]);
	ft_check_args(argc, argv);
	sig_handler();
	ft_printf("sig: %i - recebeu o sinal", sig);
	send_message(sig, argv[2]);
}
