/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:33:30 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/27 23:55:18 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	open_pipe(t_data *pipex)
{
	size_t	i;

	i = 1;
	pipex->fd = malloc(sizeof(int) * ((pipex->n_cmd - 1) * 2));
	if (!pipex->fd)
		close_data(pipex);
	while (i <= pipex->n_cmd - 1)
	{
		pipe(pipex->fd + i * 2);
		i++;
	}
}

void	close_pipe(t_data *pipex)
{
	size_t	i;

	i = 0;
	while (i < (pipex->n_cmd - 1) * 2)
	{
		close(pipex->fd[i]);
		i++;
	}
}
