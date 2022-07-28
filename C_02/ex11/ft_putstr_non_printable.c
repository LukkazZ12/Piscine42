/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:07:20 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/21 20:07:32 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*put_hexa(char *hexa)
{
	int		i;
	char	c;

	i = 0;
	c = 'a';
	while (i < 16)
	{
		if (i <= 9)
			hexa[i] = i + '0';
		else
		{
			hexa[i] = c;
			c++;
		}
		i++;
	}
	return (hexa);
}

void	ft_putstr_non_printable(char *str)
{
	char	hexa[16];
	int		i;
	int		j;

	put_hexa(hexa);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
		{
			write(1, "\\", 1);
			j = str[i];
			write(1, &hexa[j / 16], 1);
			write(1, &hexa[j % 16], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
