/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strucmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:49:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/27 23:48:52 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include "../../includes/lib_utils.h"

static t_lst	*info_cmd(t_data *pipex, char *argv)
{
	t_lst	*cmd;
	
	cmd = malloc(sizeof(t_lst));
	if (!cmd)
		return (NULL);
	cmd->cmd_opt = lib_split(argv, " ");
	if (!cmd->cmd_opt)
	{
		cmd->cmd_opt = lib_sentup("  ");
		if (!cmd->cmd_opt)
			return (free(cmd), NULL);
	}
	cmd->path_cmd = cmd_in_path(cmd->opt[0], pipex->path_env);
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
	while (path_env[i])
	{
		path_with_cmd = str_join(cmd, path_env[i]);
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
	if (!all_cmd)
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
	if (str_cmp(argv[2], "here_doc"))
		i = 3;
	while (i < argc - 2)
	{
		cmd = info_cmd(pipex, argv[i]);
		if (!cmd)
			close_data(pipex);
		add_cmd(pipex->cmd, cmd);
		i++;
	}
	free_split(pipex->path_env);
}