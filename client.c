/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:19:19 by juhur             #+#    #+#             */
/*   Updated: 2022/02/14 16:18:33 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *s)
{
	int	ret;

	ret = 0;
	while (*s != '\0')
		ret = ret * 10 + *(s++) - '0';
	return (ret);
}

void	send(int pid, char c, int count_idx)
{
	if (count_idx > 1)
		send(pid, c / 2, count_idx - 1);
	usleep(42);
	if (c & 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = -1;
		while (argv[2][++i] != '\0')
			send(pid, argv[2][i], 8);
	}
	return (0);
}
