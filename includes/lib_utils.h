/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:20:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/26 18:59:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_UTILS_H
# define LIB_UTILS_H

#include <stddef.h>

// PRINT
void	print_char(char c, int fd);
size_t	print_c(char c);
void	print_str(char *str);
// LEN
size_t	str_len(char *str);
size_t	sent_len(char **sent);
// JOIN
char	*str_join(char *str1, char *str2);
char	*str1_join(char *str1, char *str2);
char	*str2_join(char *str1, char *str2);
char	*strall_join(char *str1, char *str2);
// DUP
char	*lib_strdup(char *str);
char	*lib_strup(char *str);
// SPLIT
char	**lib_split(char *str, char *set);

#endif