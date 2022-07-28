/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hund.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 10:31:19 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);

void	print_hundred(char *str)
{
	int	j;

	j = 0;
	while (!(str[j] == '1' && str[j + 2] == '0'))
		j++;
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\n')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	hund(char *c, char *str)
{
	if (*c != '0')
	{
		uni(c, str);
		write(1, " ", 1);
		print_hundred(str);
		if (c[1] != '0')
		{
			write(1, " ", 1);
			ten(c + 1, str);
		}
		else if (c[2] != '0')
		{
			write(1, " ", 1);
			uni(c + 2, str);
		}
	}
	else
		ten(c + 1, str);
}
