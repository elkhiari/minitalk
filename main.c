/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:56:41 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/05/03 14:56:42 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void client(pid_t pid, char *txt)
{
	// printf("%s\n", txt);
	// printf("%d\n", pid);
	int i;
	int shift;
	int nbr;

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
			usleep(200);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		exit(1);
	}
	char *txt;
	pid_t PID;

	txt = argv[2];
	PID = ft_atoi(argv[1]);
	if (PID <= 0)
		exit(1);
	client(PID, txt);
	// printf("%d\n", getpid());
	// while (1)
	// 	pause();
}
