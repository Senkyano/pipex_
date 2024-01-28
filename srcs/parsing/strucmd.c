/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strucmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:49:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/28 20:13:08 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include "../../includes/lib_utils.h"
#include <stdio.h>

static char	**cmd_in_path(char *cmd, char **path_env);

static t_lst	*info_cmd(t_data *pipex, char *argv)
{
	t_lst	*cmd;
	
	cmd = malloc(sizeof(t_lst));
	if (!cmd)
		return (NULL);
	if (argv[0] != '\0')
		cmd->cmd_opt = lib_split(argv, " ");
	if (argv[0] == 0 || !cmd->cmd_opt)
	{
		if (argv[0] == 0)
			cmd->cmd_opt = lib_sentup(" ");
		if (!cmd->cmd_opt)
			return (free(cmd), NULL);
	}
	cmd->path_cmd = cmd_in_path(cmd->cmd_opt[0], pipex->path_env);
	if (!cmd->path_cmd)
		return (free_split(cmd->cmd_opt), free(cmd), NULL);
	cmd->next = NULL;
	return (cmd);
}

static char	**cmd_in_path(char *cmd, char **path_env)
{
	size_t	i;
	char	**path_with_cmd;

	path_with_cmd = malloc(sizeof(char *) * (sent_len(path_env) + 1));
	if (!path_with_cmd)
		return (NULL);
	i = 0;
	while (path_env[i])
	{
		path_with_cmd[i] = str_join(path_env[i], cmd);
		if (!path_with_cmd)
			return (free(path_with_cmd), NULL);
		i++;
	}
	path_with_cmd[i] = NULL;
	return (path_with_cmd);
}

static void	add_cmd(t_lst **all_cmd, t_lst *cmd)
{
	t_lst	*curr;
	
	curr = *all_cmd;
	if (!(*all_cmd))
	{
		*all_cmd = cmd;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = cmd;
}

void	do_lst_cmd(t_data *pipex, char **argv, int argc)
{
	size_t	i;
	t_lst	*cmd;

	i = 2;
	pipex->n_cmd = argc - (i + 1);
	if (str_cmp(argv[1], "here_doc"))
	{
		i = 3;
		pipex->n_cmd--;
	}
	while ((int)i < argc - 2)
	{
		cmd = info_cmd(pipex, argv[i]);
		if (!cmd)
			close_data(pipex, 1);
		add_cmd(&pipex->cmd, cmd);
		i++;
	}
	free_split(pipex->path_env);
	pipex->path_env = NULL;
}

void	print_lst(t_lst *lst_cmd)
{
	t_lst	*curr;

	curr = lst_cmd;
	while (curr)
	{
		print_sent(curr->path_cmd);
		printf("\n");
		print_sent(curr->cmd_opt);
		curr = curr->next;
	}
}
