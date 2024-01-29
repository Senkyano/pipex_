/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:30 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/29 15:20:14 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include "../../includes/lib_utils.h"
#include <unistd.h>

void	cmd_is_find(t_data *pipex, t_lst *cmd)
{
	size_t	i;

	i = 0;
	while (cmd->path_cmd[i])
	{
		if (access(cmd->path_cmd[i], X_OK) == 0)
		{
			cmd->cmd_find = cmd->path_cmd[i];
			return ;
		}
		i++;
	}
	print_error(cmd->cmd_opt[0]);
	print_error(" : no such file directory\n");
	close_data(pipex, 1);
}
