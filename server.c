/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:19:31 by juhur             #+#    #+#             */
/*   Updated: 2022/02/14 18:25:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static char	g_string[9];

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static void	print_number(int number, char *charset, int base)
{
	if (number / base)
		print_number(number / base, charset, base);
	write(1, &charset[number % base], 1);
}

static void	handler(int signo)
{
	int	i;
	int	num;

	if (signo == 30)
		g_string[ft_strlen(g_string)] = '0';
	else
		g_string[ft_strlen(g_string)] = '1';
	if (ft_strlen(g_string) == 8)
	{
		i = -1;
		num = 0;
		while (++i < 9)
		{
			if (i < 8)
				num = (num << 1) + g_string[i] - '0';
			g_string[i] = '\0';
		}
		write(1, &num, 1);
	}
}

int	main(void)
{
	void	(*hand)(int);
	int		i;

	print_number(getpid(), "0123456789", 10);
	write(1, "\n", 1);
	i = -1;
	while (++i < 9)
		g_string[i] = '\0';
	hand = signal(SIGUSR1, handler);
	hand = signal(SIGUSR2, handler);
	while (1)
		;
	return (0);
}
