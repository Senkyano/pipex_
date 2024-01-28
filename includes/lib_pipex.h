/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:16:48 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/28 18:38:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include <stdlib.h>

typedef struct s_lst
{
	int				n_fork;
	char			**path_cmd;
	char			**cmd_opt;
	struct s_lst	*next;
} t_lst;

typedef	struct s_data
{
	t_lst	*cmd;
	size_t	n_cmd;
	int		in_file;
	int		out_file;
	int		*fd;
	char	**path_env;
} t_data;

void	get_path(t_data *pipex, char **env);
void	open_pipe(t_data *pipex);
void	access_file(t_data *pipex, char **argv, int argc);
// CLOSE
void	close_pipe(t_data *pipex);
void	close_data(t_data *pipex, int ok);

void	do_lst_cmd(t_data *pipex, char **argv, int argc);
void	print_lst(t_lst *lst_cmd);

#endif