/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trillion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 08:12:07 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);
void	billion(char *c, char *str, int i);

void	print_trillion(char *str)
{
	int	j;

	write(1, " ", 1);
	j = 0;
	while (!(str[j] == '1' && str[j + 12] == '0'))
		j++;
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\n')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	trillion(char *c, char *str, int i)
{
	int	k;

	if (i == 13)
		uni(c, str);
	else if (i == 14)
		ten(c, str);
	else if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		hund(c, str);
	if (!(*c == '0' && *(c + 1) == '0' && *(c + 2) == '0'))
		print_trillion(str);
	if (!(*(c + i - 12) == '0' && *(c + i - 11) == '0' && *(c + i - 10) == '0'))
		write (1, " ", 1);
	k = 1;
	while (k <= 12)
	{
		if (c[i - k] == '0')
			k++;
		else
			break ;
	}
	if (k != 13)
		billion(c + i - 12, str, 12);
}
