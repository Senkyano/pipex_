/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/28 20:05:37 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stdlib.h>

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

char	*lib_strup(char *str)
{
	size_t	i;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (str_len(str) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}

char	**lib_sentup(char *str)
{
	char	**new_sent;

	if (!str)
		return (NULL);
	new_sent = malloc(sizeof(char *) * 2);
	if (!new_sent)
		return (NULL);
	new_sent[0]= lib_strup(str);
	if (!new_sent[0])
		return (free(new_sent), NULL);
	new_sent[1] = NULL;
	return (new_sent);
}

