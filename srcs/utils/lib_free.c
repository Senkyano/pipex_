/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:00:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/27 22:48:51 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stdlib.h>

void	free_split(char **sent)
{
	size_t	i;

	i = 0;
	while (sent[i])
		free(sent[i++]);
	free(sent);
}
