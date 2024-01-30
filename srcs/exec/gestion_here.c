/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_here.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:04:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/30 23:18:41 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include "../../includes/lib_utils.h"
#include "../../includes/get_next_line.h"

void	file_heredoc(t_data *pipex, char *lim)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(STDIN_FILENO, lim);
		if (!str)
		{
			if (str != NULL)
				free(str);
			close(lim);
			return ;
		}
		write_str_fd(str, pipex->in_file);
		free(str);
	}
}
