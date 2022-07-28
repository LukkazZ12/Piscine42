/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quintillion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 08:21:13 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);
void	quadrillion(char *c, char *str, int i);

void	print_quintillion(char *str)
{
	int	j;
	int	k;

	j = 0;
	while (!(str[j] == '1' && str[j + 18] == '0'))
	{
		j++;
		if (str[j] == '1' && str[j + 18] == '0')
		{
			k = 0;
			while (k < 19)
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

void	quintillion(char *c, char *str, int i)
{
	int	k;

	if (i == 19)
		uni(c, str);
	else if (i == 20)
		ten(c, str);
	else if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		hund(c, str);
	if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
	{
		write(1, " ", 1);
		print_quintillion(str);
	}
	if (!(*(c + i - 18) == '0' && *(c + i - 17) == '0' && *(c + i - 16) == '0'))
		write (1, " ", 1);
	k = 1;
	while (k <= 18)
	{
		if (c[i - k] == '0')
			k++;
		else
			break ;
	}
	if (k != 19)
		quadrillion(c + i - 18, str, 18);
}
