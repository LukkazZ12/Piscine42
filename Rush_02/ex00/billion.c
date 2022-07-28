/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   billion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 09:55:05 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);
void	million(char *c, char *str, int i);

void	print_billion(char *str)
{
	int	j;

	write (1, " ", 1);
	j = 0;
	while (!(str[j] == '1' && str[j + 9] == '0'))
		j++;
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\n')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	billion(char *c, char *str, int i)
{
	int	k;

	if (i == 10)
		uni(c, str);
	else if (i == 11)
		ten (c, str);
	else if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		hund(c, str);
	if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		print_billion(str);
	if (!(*(c + i - 9) == '0' && *(c + i - 8) == '0' && *(c + i - 7) == '0'))
		write (1, " ", 1);
	k = 1;
	while (k <= 9)
	{
		if (c[i - k] == '0')
			k++;
		else
			break ;
	}
	if (k != 10)
		million(c + i - 9, str, 9);
}
