/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:15:35 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/26 17:22:12 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"

void	print_char(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

void	print_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		print_char(str[i]);
}

void	print_error(char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		print_char(str[i], 2);
}
