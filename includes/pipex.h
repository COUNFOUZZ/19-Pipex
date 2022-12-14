/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:01:49 by aabda             #+#    #+#             */
/*   Updated: 2022/09/28 17:13:05 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		pid_1;
	int		pid_2;
	int		status;
	int		fd_pipe[2];
	char	*path_cmd1;
	char	*path_cmd2;
	char	**cmd1;
	char	**cmd2;
}	t_data;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*cmd_exist(char	*cmd, char **paths);
char	**ft_split(char const *s, char c);
char	**getcmd(char *s);
void	initialize_struct(t_data *data, char **argv);
void	child1(t_data data, char **envp);
void	child2(t_data data, char **envp);
void	parent(t_data data);
void	ft_error(int ret);
void	ft_cmd_not_found(char *path_cmd, char	**cmd);

#endif