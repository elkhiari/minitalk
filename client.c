/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:56:24 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/05/03 14:56:29 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client(pid_t pid, char *txt)
{
	int	i;
	int	shift;
	int	nbr;

	i = 0;
	while (txt[i])
	{
		shift = 0;
		while (shift < 8)
		{
			nbr = 128 >> shift;
			if ((nbr & txt[i]) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*txt;

	if (argc != 3)
		exit (1);
	txt = argv[2];
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		exit (1);
	client(pid, txt);
}
