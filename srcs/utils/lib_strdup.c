/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/26 16:50:10 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"

char	*lib_strdup(char *str)
{
	size_t	i;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (str_len(str) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i++])
		new_str[i] = str[i];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
