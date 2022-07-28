/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrillion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 08:14:38 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);
void	trillion(char *c, char *str, int i);

void	print_quadrillion(char *str)
{
	int	j;
	int	k;

	j = 0;
	while (!(str[j] == '1' && str[j + 15] == '0'))
	{
		j++;
		if (str[j] == '1' && str[j + 15] == '0')
		{
			k = 0;
			while (k < 16)
			{
				if (str[j + k] == '\n')
					j = j + k;
				k++;
			}
		}
	}
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\n')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	quadrillion(char *c, char *str, int i)
{
	int	k;

	if (i == 16)
		uni(c, str);
	else if (i == 17)
		ten(c, str);
	else if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		hund(c, str);
	if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
	{
		write(1, " ", 1);
		print_quadrillion(str);
	}
	if (!(*(c + i - 15) == '0' && *(c + i - 14) == '0' && *(c + i - 13) == '0'))
		write (1, " ", 1);
	k = 1;
	while (k <= 15)
	{
		if (c[i - k] == '0')
			k++;
		else
			break ;
	}
	if (k != 16)
		trillion(c + i - 15, str, 15);
}
