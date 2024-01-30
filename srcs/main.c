/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:55:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/30 17:00:30 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_pipex.h"
#include "../includes/lib_utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static bool	check_condition(int	argc, const char **argv, const char **env);
static void	init_data(t_data *pipex);

int	main(int argc, const char **argv, const char **env)
{
	t_data	pipex;

	if (check_condition(argc, argv, env) == false)
		exit(0);
	init_data(&pipex);
	get_path(&pipex, (char **)env);
	do_lst_cmd(&pipex, (char **)argv, argc);
	access_file(&pipex, (char **)argv, argc);
	if (pipex.here_doc == true)
		file_heredoc(&pipex, (char *)argv[2]);
	file_to_file(&pipex, (char **)env);
	close_data(&pipex, 0);
	return (0);
}

static void	init_data(t_data *pipex)
{
	pipex->cmd = NULL;
	pipex->n_cmd = 0;
	pipex->in_file = -1;
	pipex->out_file = -1;
	pipex->fd = NULL;
	pipex->path_env = NULL;
	pipex->here_doc = false;
}
void	free_cmd(t_data *pipex)
{
	t_lst	*curr;

	while (pipex->cmd)
	{
		curr = pipex->cmd;
		pipex->cmd = pipex->cmd->next;
		free_split(curr->path_cmd);
		free_split(curr->cmd_opt);
		free(curr);
	}
}

void	close_data(t_data *pipex, int ok)
{
	if (pipex->path_env)
		free_split(pipex->path_env);
	if (pipex->in_file != -1)
		close(pipex->in_file);
	if (pipex->out_file != -1)
		close(pipex->out_file);
	if (pipex->fd)
	{
		close_pipe(pipex);
		free(pipex->fd);
	}
	if (pipex->cmd)
		free_cmd(pipex);
	if (ok == 1)
	{
		exit(1);
	}
}

static bool	check_condition(int	argc, const char **argv, const char **env)
{
	if (!env)
	{
		print_error("env doesn't exist\n");
		return (false);
	}
	if (argc < 5 && str_equal((char *)argv[1], "here_doc") == false)
	{
		print_error("Not enough arguments\n");
		return (false);
	}
	if (str_equal((char *)argv[1], "here_doc") == true)
	{
		if (argc < 6)
		{
			print_error("Not enough arguments for here_doc\n");
			return (false);
		}
	}
	return (true);
}
