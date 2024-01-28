/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:15:35 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/28 18:08:42 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <unistd.h>
#include <stddef.h>

void	print_char(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

void	print_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		print_c(str[i++]);
}

void	print_error(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		print_char(str[i++], 2);
}

void	print_sent(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		print_str(str[i]);
		print_str("\n");
		i++;
	}
}
