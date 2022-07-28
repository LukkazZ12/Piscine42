/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_1_to_39.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 04:23:21 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str);
void	ten(char *c, char *str);
void	hund(char *c, char *str);
void	thousand(char *c, char *str, int i);
void	million(char *c, char *str, int i);
void	billion(char *c, char *str, int i);
void	trillion(char *c, char *str, int i);
void	quadrillion(char *c, char *str, int i);
void	quintillion(char *c, char *str, int i);
void	sextillion(char *c, char *str, int i);
void	septillion(char *c, char *str, int i);
void	octillion(char *c, char *str, int i);
void	nonillion(char *c, char *str, int i);
void	decillion(char *c, char *str, int i);
void	undecillion(char *c, char *str, int i);

void	i_1_to_18(char *c, char *str, int i)
{
	if (i == 1)
		uni(c, str);
	else if (i == 2)
		ten(c, str);
	else if (i == 3)
		hund(c, str);
	else if (i <= 6)
		thousand(c, str, i);
	else if (i <= 9)
		million(c, str, i);
	else if (i <= 12)
		billion(c, str, i);
	else if (i <= 15)
		trillion(c, str, i);
	else if (i <= 18)
		quadrillion(c, str, i);
}

void	i_19_to_39(char *c, char *str, int i)
{
	if (i <= 21)
		quintillion(c, str, i);
	else if (i <= 24)
		sextillion(c, str, i);
	else if (i <= 27)
		septillion(c, str, i);
	else if (i <= 30)
		octillion(c, str, i);
	else if (i <= 33)
		nonillion(c, str, i);
	else if (i <= 36)
		decillion(c, str, i);
	else if (i <= 39)
		undecillion(c, str, i);
	else
		write(1, "Dict Error\n", 11);
}

void	i_1_to_39(char *c, char *str, int i)
{
	if (i >= 1 && i <= 18)
		i_1_to_18(c, str, i);
	else
		i_19_to_39(c, str, i);
}
