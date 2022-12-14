/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:33:50 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/11 16:03:08 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int k)
{
	char	c;

	c = k / 10 + '0';
	write(1, &c, 1);
	c = k % 10 + '0';
	write(1, &c, 1);
}	

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			print(i);
			write(1, " ", 1);
			print(j);
			if (!(i == 98))
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
