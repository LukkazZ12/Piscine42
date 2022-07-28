/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 09:55:05 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*void	sign(char *str)
{
	int	i;


}*/

void	ver_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (str[i] == '-' || str[i] == '+')
			i++;
		else if (str[i] < '0' || str[i] > '9')
			str[i] = '\0';
		else if (str[i] < '0' || str[i] > '9')
			
			i++;
	printf("%s", str);
	return ;
}

//int	ft_atoi(char *str)
//{
	//int	i;
	//int	j;
	//int	num;
int	main(void)
{
	ver_str("++++++----+-+-+-+-+-1203+");

	
    
    
    
    /*num = 0;
	i = 0;
	while (i < i)
	{
		j = str[i] - '0';
		num = num * 10 + j;
		i++;
	}*/
	return (0);
}
