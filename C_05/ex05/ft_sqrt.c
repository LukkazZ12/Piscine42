/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:14:24 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/25 21:26:37 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i <= 46340)
	{
		if (i * i < nb)
			i++;
		else if (i * i == nb)
			return (i);
		else
			return (0);
	}
	return (0);
}