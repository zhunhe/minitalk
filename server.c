/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:19:31 by juhur             #+#    #+#             */
/*   Updated: 2022/02/14 20:22:55 by juhur            ###   ########.fr       */
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
	int		i;
	char	c;

	if (signo == SIGUSR1)
		g_string[ft_strlen(g_string)] = '0';
	else
		g_string[ft_strlen(g_string)] = '1';
	if (ft_strlen(g_string) == 8)
	{
		i = -1;
		c = 0;
		while (++i < 8)
		{
			c = (c << 1) + g_string[i] - '0';
			g_string[i] = '\0';
		}
		write(1, &c, 1);
	}
}

int	main(void)
{
	print_number(getpid(), "0123456789", 10);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		;
	return (0);
}
