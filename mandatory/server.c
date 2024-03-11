/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:12 by gabriela          #+#    #+#             */
/*   Updated: 2024/03/09 14:00:40 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "../libft/libft.h"

void	receive_message(int signal)
{
	static unsigned char	buff;
	static int				i_bit;

	if (signal == SIGUSR1)
		buff |= 1;
	i_bit++;
	if (i_bit == 8)
	{
		write(1, &buff, 1);
		i_bit = 0;
		buff = 0;
	}
	else
		buff = buff << 1;
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &receive_message;
	sa.sa_flags = 0;
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
}
