/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undecillion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 10:28:59 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);
void	decillion(char *c, char *str, int i);

void	print_undecillion(char *str)
{
	int	j;
	int	k;

	j = 0;
	while (!(str[j] == '1' && str[j + 36] == '0'))
	{
		j++;
		if (str[j] == '1' && str[j + 36] == '0')
		{
			k = 0;
			while (k < 37)
			{
				if (str[j + k] == '\n')
					j = j + k;
				k++;
			}
		}
	}
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	undecillion(char *c, char *str, int i)
{
	int	k;

	if (i == 37)
		uni(c, str);
	else if (i == 38)
		ten(c, str);
	else if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		hund(c, str);
	if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
	{
		write(1, " ", 1);
		print_undecillion(str);
	}
	if (!(*(c + i - 36) == '0' && *(c + i - 35) == '0' && *(c + i - 34) == '0'))
		write (1, " ", 1);
	k = 1;
	while (k <= 36)
	{
		if (c[i - k] == '0')
			k++;
		else
			break ;
	}
	if (k != 37)
		decillion(c + i - 36, str, 36);
}
