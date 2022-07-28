/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/23 12:14:20 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	uni(char *c, char *str) // buscar no dicionário e escrever o número da unidade em si
{	
	int	j;

	j = 0;
	while (str[j] != *c) //procura n na buff e escreve o nome
		j++;
	while (str[j] < 'a' || str[j] > 'z') //verifica se é espaço ou dois pontos
		j++;
	while (str[j] != '\n') //encontra a letra e escreve
	{
		write(1, &str[j], 1);
		j++;
	}
}
