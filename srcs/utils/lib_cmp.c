/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:56:55 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/26 18:49:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stdbool.h>

bool	str_cmp(char *str, char *str2)
{
	size_t	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}

bool	str_ncmp(char *str, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && str2[i] && i < n)
	{
		if (str[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}
