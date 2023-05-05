/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:56:32 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/05/03 14:56:37 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_to_char(int tab[])
{
	int				s;
	int				res;
	int				n;

	s = 0;
	n = 128;
	res = 0;
	while (s < 8)
	{
		res += tab[s] * n;
		n = n / 2;
		s++;
	}
	ft_putchar(res);
}

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static pid_t	pid;
	static int		arr[8];
	static int		g_a;

	(void)ucontext;
	if (pid != info->si_pid)
	{
		g_a = 0;
		pid = info->si_pid;
		ft_putchar('\n');
	}
	if (sig == SIGUSR1)
		arr[g_a] = 0;
	else
		arr[g_a] = 1;
	g_a++;
	if (g_a == 8)
	{
		g_a = 0;
		convert_to_char(arr);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_sigaction = &handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
