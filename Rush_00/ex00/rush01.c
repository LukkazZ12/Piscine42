/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:57:52 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/10 20:58:32 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SUP_LEFT '/'
#define INF_LEFT '\\'
#define SUP_RIGHT '\\'
#define INF_RIGHT '/'
#define EDGE_H '*'
#define EDGE_V '*'
#define FILL  ' '

void	print(int i, int j, int x, int y);

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		i;
	int		j;

	if (x <= 0 || y <= 0)
		return ;
	j = 1;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{	
			print(i, j, x, y);
			if (i == x)
				ft_putchar('\n');
			i++;
		}
		j++;
	}
}

void	print(int i, int j, int x, int y)
{
	if (i == 1 && j == 1)
		ft_putchar(SUP_LEFT);
	else if (i == x && j == 1)
		ft_putchar(SUP_RIGHT);
	else if (i == 1 && j == y)
		ft_putchar(INF_LEFT);
	else if (i == x && j == y)
		ft_putchar(INF_RIGHT);
	else if (i == 1 || i == x)
		ft_putchar(EDGE_V);
	else if (j == 1 || j == y)
		ft_putchar(EDGE_H);
	else
		ft_putchar(FILL);
}
