/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_here.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:04:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/21 12:58:08 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_pipex.h"
#include "../../includes/lib_utils.h"
#include "../../includes/get_next_line.h"

void	file_heredoc(t_data *pipex)
{
	char	*str;
	int		file;

	file = open(".here_doc-tmp.tmp", O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (file < 0)
		close_data(pipex, 1);
	while (1)
	{
		print_str("> ");
		str = get_next_line(STDIN_FILENO, pipex->lim);
		if (!str)
		{
			close(file);
			pipex->in_file = open(".here_doc-tmp.tmp", O_RDONLY);
			if (pipex->in_file < 0)
				close_data(pipex, 1);
			unlink(".here_doc-tmp.tmp");
			return ;
		}
		write_str_fd(str, file);
		free(str);
	}
}
