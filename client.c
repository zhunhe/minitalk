/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:19:19 by juhur             #+#    #+#             */
/*   Updated: 2022/02/14 13:24:52 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

int	ft_atoi(char *s)
{
	int	ret;

	ret = 0;
	while (*s != '\0')
		ret = ret * 10 + *(s++) - '0';
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		kill(ft_atoi(argv[1]), 1);
	return (0);
}
