/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:32:04 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/11 19:14:55 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_pointer(size_t *ptr, int *count)
{
	char			*convert;
	size_t			temp_ptr;
	char			pointer[25];
	size_t			index;

	temp_ptr = (size_t) ptr;
	convert = BASE_HEXA_LOWER;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	write(1, "0x", 2);
	*count += 2;
	index = 0;
	while (temp_ptr > 0)
	{
		pointer[index] = convert[temp_ptr % 16];
		temp_ptr = temp_ptr / 16;
		index++;
	}
	while (index--)
		ft_putchar_printf(pointer[index], count);
}
