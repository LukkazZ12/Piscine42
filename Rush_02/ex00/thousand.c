/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thousand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 07:55:25 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);

void	print_thousand(char *str)
{
	int	j;

	write(1, " ", 1);
	j = 0;
	while (!(str[j] == '1' && str[j + 3] == '0'))
		j++;
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\n')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	thousand(char *c, char *str, int i)
{
	int	k;

	if (i == 4)
		uni(c, str);
	else if (i == 5)
		ten(c, str);
	else if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		hund(c, str);
	if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		print_thousand(str);
	if (!(*(c + i - 3) == '0' && *(c + i - 2) == '0' && *(c + i - 1) == '0'))
		write (1, " ", 1);
	k = 1;
	while (k <= 3)
	{
		if (c[i - k] == '0')
			k++;
		else
			break ;
	}
	if (k != 4)
		hund(c + i - 3, str);
}
