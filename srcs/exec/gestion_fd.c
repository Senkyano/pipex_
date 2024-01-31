/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:33:30 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/31 16:38:10 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include "../../includes/lib_utils.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

void	access_file(t_data *pipex, char **argv, int arg)
{
	pipex->out_file = open(argv[arg - 1], O_RDWR | O_CREAT | O_APPEND, 0666);
	if (pipex->out_file == -1)
		close_data(pipex, 1);
	if (in_lim(argv[1], "here_doc") == false)
	{
		if (access(argv[1], F_OK | R_OK) == -1)
		{
			print_str("Wrong infile\n");
			close_data(pipex, 1);
		}
		pipex->in_file = open(argv[1], O_RDONLY);
	}
	else
	{
		pipex->here_doc = true;
		pipex->lim = argv[2];
	}
	open_pipe(pipex);
}

void	open_pipe(t_data *pipex)
{
	size_t	i;

	i = 0;
	pipex->fd = malloc(sizeof(int) * ((pipex->n_cmd - 1) * 2));
	if (!pipex->fd)
		close_data(pipex, 1);
	while (i < pipex->n_cmd - 1)
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
