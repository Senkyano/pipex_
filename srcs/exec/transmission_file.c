/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmission_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:17:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/30 17:02:19 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include "../../includes/lib_utils.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void	child(t_data *pipex, t_lst *cmd, size_t i, char **env);
static void	redirection(t_data *pipex, int	in, int out);
static void	closing_file(t_data *pipex);

void	file_to_file(t_data *pipex, char **env)
{
	t_lst	*curr_cmd;
	size_t	i;

	i = 0;
	curr_cmd = pipex->cmd;
	// if (pipex->here_doc == true)
		
	while (curr_cmd)
	{
		child(pipex, curr_cmd, i, env);
		curr_cmd = curr_cmd->next;
		i += 2;
	}
	closing_file(pipex);
	curr_cmd = pipex->cmd;
	while (curr_cmd)
	{
		waitpid(curr_cmd->n_fork, NULL, 0);
		curr_cmd = curr_cmd->next;
	}
}

static void	closing_file(t_data *pipex)
{
	close_pipe(pipex);
	free(pipex->fd);
	pipex->fd = NULL;
	close(pipex->in_file);
	close(pipex->out_file);
	if (pipex->here_doc == true)
		unlink(".here_doc.tmp");
}

static void	redirection(t_data *pipex, int in, int out)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		print_error("dup2() ");
		close_data(pipex, 1);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		print_error("dup2() ");
		close_data(pipex, 1);
	}
}

static void	out_direction(t_data *pipex, int in, int out)
{
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		print_error("dup2() ");
		close_data(pipex, 1);
	}
	if (dup2(in, STDIN_FILENO) == -1)
	{
		print_error("dup2() ");
		close_data(pipex, 1);
	}
}

static void	child(t_data *pipex, t_lst *cmd, size_t i, char **env)
{
	cmd->n_fork = fork();
	if (cmd->n_fork == -1)
	{
		print_error("fork don't work\n");
		close_data(pipex, 1);
	}
	else if (cmd->n_fork == 0)
	{
		if (i == 0)
			redirection(pipex, pipex->in_file, pipex->fd[i + 1]);
		else if (i < ((pipex->n_cmd - 1) * 2))
			redirection(pipex, pipex->fd[i - 2], pipex->fd[i + 1]);
		else if (i == ((pipex->n_cmd - 1) * 2))
			out_direction(pipex, pipex->fd[i - 2], pipex->out_file);
		close_pipe(pipex);
		close(pipex->in_file);
		close(pipex->out_file);
		cmd_is_find(pipex, cmd);
		if (execve(cmd->cmd_find, cmd->cmd_opt, env) == -1)
		{
			print_error("execve() ");
			close_data(pipex, 1);
		}
	}
}
