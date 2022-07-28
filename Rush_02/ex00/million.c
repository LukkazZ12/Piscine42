/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   million.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 10:33:38 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);
void	thousand(char *c, char *str, int i);

void	print_million(char *str)
{
	int	j;

	write(1, " ", 1);
	j = 0;
	while (!(str[j] == '1' && str[j + 6] == '0'))
		j++;
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\n')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	million(char *c, char *str, int i)
{
	int	k;

	if (i == 7)
		uni(c, str);
	else if (i == 8)
		ten(c, str);
	else if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		hund(c, str);
	if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		print_million(str);
	if (!(*(c + i - 6) == '0' && *(c + i - 5) == '0' && *(c + i - 4) == '0'))
		write (1, " ", 1);
	k = 1;
	while (k <= 6)
	{
		if (c[i - k] == '0')
			k++;
		else
			break ;
	}
	if (k != 7)
		thousand(c + i - 6, str, 6);
}
