/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:19:31 by juhur             #+#    #+#             */
/*   Updated: 2022/02/14 13:02:37 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int number, char *charset, int base)
{
	if (number / base)
		print_number(number / 10, charset, base);
	write(1, &charset[number % base], 1);
}

int	main(void)
{
	print_number(getpid(), "0123456789", 10);
	return (0);
}
