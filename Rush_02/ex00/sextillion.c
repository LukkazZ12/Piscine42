/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sextillion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 08:28:42 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);
void	quintillion(char *c, char *str, int i);

void	print_sextillion(char *str)
{
	int	j;
	int	k;

	j = 0;
	while (!(str[j] == '1' && str[j + 21] == '0'))
	{
		j++;
		if (str[j] == '1' && str[j + 21] == '0')
		{
			k = 0;
			while (k < 22)
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

void	sextillion(char *c, char *str, int i)
{
	int	k;

	if (i == 22)
		uni(c, str);
	else if (i == 23)
		ten(c, str);
	else if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		hund(c, str);
	if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
	{
		write(1, " ", 1);
		print_sextillion(str);
	}
	if (!(*(c + i - 21) == '0' && *(c + i - 20) == '0' && *(c + i - 19) == '0'))
		write (1, " ", 1);
	k = 1;
	while (k <= 21)
	{
		if (c[i - k] == '0')
			k++;
		else
			break ;
	}
	if (k != 22)
		quintillion(c + i - 21, str, 21);
}
