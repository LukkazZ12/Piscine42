/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 07:50:25 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);

void	one(char *c, char *str)
{
	int	j;

	j = 0;
	while (!(str[j] == c[0] && str[j + 1] == c[1]))
		j++;
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\n')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	two_or_more(char *c, char *str)
{
	int	j;

	j = 0;
	while (!(str[j] == c[0] && str[j + 1] == '0'))
		j++;
	while (str[j] < 'a' || str[j] > 'z')
		j++;
	while (str[j] != '\n')
	{
		write(1, &str[j], 1);
		j++;
	}
	if (c[1] != '0')
	{
		write(1, " ", 1);
		uni(c + 1, str);
	}
}

void	ten(char *c, char *str)
{
	if (*c == '0') //se for zero entra na uni
		uni(c + 1, str);
	else if (c[0] == '1') //se for 1 entra na one
		one(c, str);
	else
		two_or_more(c, str); //cado não entra na two ou more
}
