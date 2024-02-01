/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:23:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/01 17:28:49 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include "../../includes/lib_utils.h"
#include <stdlib.h>

static char	*go_to_path(char **env);

void	get_path(t_data *pipex, char **env)
{
	char	*path;
	size_t	i;

	i = 0;
	path = go_to_path(env);
	if (!path)
		exit(1);
	pipex->path_env = lib_split(&path[5], ":");
	if (!pipex->path_env)
		close_data(pipex, 1);
	while (pipex->path_env[i])
	{
		pipex->path_env[i] = str1_join(pipex->path_env[i], "/");
		i++;
	}
}

static char	*go_to_path(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (str_cmp(env[i], "PATH="))
			return (env[i]);
		i++;
	}
	print_error("PATH=, not found\n");
	return (NULL);
}
