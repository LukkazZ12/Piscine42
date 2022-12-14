/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:17 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/24 04:23:21 by elais-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int		ver_uns_int(char *c, int i);
void	i_1_to_39(char *c, char *str, int i);

void	zero(char *c)
{
	int	i;
	int	k;

	k = 0;
	while (c[k] == '0')
		k++;
	if (c[k] == '\0')
	{
		c[0] = '0';
		c[1] = '\0';
	}
	else
	{
		i = 0;
		while (c[k] != '\0')
		{	
			c[i] = c[k];
			i++;
			k++;
		}
		c[i] = '\0';
	}
}

int	read_num(char *c, char *str, int i)
{
	int	n;

	n = read(i, str, 4096);
	close(i);
	str[n] = '\0';
	n = 0;
	while (c[n] != '\0')
	{
		if (c[n] < '0' || c[n] > '9')
			return (-1);
		n++;
	}
	zero(c);
	n = 0;
	while (c[n] != '\0')
		n++;
	if (ver_uns_int(c, n) == 1)
		return (-1);
	return (n);
}

int	error(int l, char *c)
{	
	int	i;

	if (l != 1 && l != 2)
		return (-1);
	else if (l == 1)
	{
		i = open("numbers.dict", O_RDONLY);
		if (c[0] == '\0')
			return (-1);
	}
	else
		i = open(c, O_RDONLY);
	if (i == -1)
		return (-1);
	return (i);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			j;
	int			l;
	char		buf[4096];

	l = argc - 1;
	j = error(l, argv[1]);
	if (j == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}	
	else
		i = read_num(argv[l], buf, j);
	if (i == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i_1_to_39(argv[l], buf, i);
	return (0);
}
