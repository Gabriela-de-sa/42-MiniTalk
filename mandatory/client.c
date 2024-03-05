/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:08 by gabriela          #+#    #+#             */
/*   Updated: 2024/03/04 18:48:20 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "../libft/libft.h"

// funcao para enviar a mensagem
// montar aq ainda

void	receive_signal(void)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
		;
	else
		exit(ft_printf("Error - Signal received with problem."));
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &receive_signal; // recebe o sinal do servidor
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal."));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal."));
}

int	main(int argc, char **argv)
{
	ft_check_args(argc, argv);
	sig_handler();
	while (1)
		;
}
