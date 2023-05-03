/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:55:56 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/05/03 15:48:56 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int	nbr;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr %= 10;
	}
	ft_putchar(nbr % 10 + '0');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	nbr;

	i = 1;
	j = 0;
	nbr = 0;
	while (str[j] == '32' || (str[j] >= '9' && str[j] <= '13'))
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			i = -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		nbr = nbr * 10 + (str[j] - '0');
		j++;
	}
	return (nbr * i);
}
