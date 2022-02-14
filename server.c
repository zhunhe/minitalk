/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:19:31 by juhur             #+#    #+#             */
/*   Updated: 2022/02/14 17:38:18 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	print_number(int number, char *charset, int base)
{
	if (number / base)
		print_number(number / base, charset, base);
	write(1, &charset[number % base], 1);
}

void	handler(int signo)
{
	if (signo == 30)
		write(1, "0", 1);
	else
		write(1, "1", 1);
}

int	main(void)
{
	void	(*hand)(int);

	print_number(getpid(), "0123456789", 10);
	write(1, "\n", 1);
	hand = signal(SIGUSR1, handler);
	hand = signal(SIGUSR2, handler);
	while (1)
		;
	return (0);
}
