/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:16:48 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/31 16:23:55 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_lst
{
	pid_t				n_fork;
	char			**path_cmd;
	char			**cmd_opt;
	char			*cmd_find;
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
	bool	here_doc;
	char	*lim;
} t_data;

void	file_heredoc(t_data *pipex);
void	get_path(t_data *pipex, char **env);
void	open_pipe(t_data *pipex);
void	access_file(t_data *pipex, char **argv, int argc);
// CLOSE
void	close_pipe(t_data *pipex);
void	close_data(t_data *pipex, int ok);

void	do_lst_cmd(t_data *pipex, char **argv, int argc);
void	print_lst(t_lst *lst_cmd);

void	file_to_file(t_data *pipex, char **env);
void	cmd_is_find(t_data *pipex, t_lst *cmd);

#endif