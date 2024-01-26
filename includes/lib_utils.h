/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:20:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/26 17:19:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_UTILS_H
# define LIB_UTILS_H

// PRINT
void	print_char(char c);
size_t	print_char(char c);
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
// SPLIT
char	**lib_split(char *str, char *set);

#endif