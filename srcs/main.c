/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:55:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/26 17:23:47 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include "../../includes/lib_utils.h"
#include <stdbool.h>

int	main(int argc, const char **argv, const char **env)
{
	if (check_condition(argc, argv, env) == false)
		exit(0);
}

bool	check_condition(int	argc, const char **argv, const char **env)
{
	if (!env)
	{
		print_error("env doesn't exist\n");
		return (false);
	}
	if (argc < 5)
	{
		print_error("Not enough arguments\n");
		return (false);
	}
	if (str_cmp(argv[1], "here_doc") == true)
	{
		if (argc < 6)
		{
			print_error("Not enough arguments for here_doc\n");
			return (false);
		}
	}
	return (true);
}
