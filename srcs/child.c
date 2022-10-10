/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:11:05 by aabda             #+#    #+#             */
/*   Updated: 2022/10/10 14:43:53 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child1(t_data data, char **envp)
{
	ft_error(dup2(data.infile, STDIN_FILENO));
	ft_error(dup2(data.fd_pipe[1], STDOUT_FILENO));
	ft_error(close(data.fd_pipe[0]));
	ft_error(close(data.fd_pipe[1]));
	data.path_cmd1 = cmd_exist(data.cmd1[0], envp);
	ft_cmd_not_found(data.path_cmd1, data.cmd1);
	ft_error(execve(data.path_cmd1, data.cmd1, NULL));
}

void	child2(t_data data, char **envp)
{
	ft_error(dup2(data.fd_pipe[0], STDIN_FILENO));
	ft_error(dup2(data.outfile, STDOUT_FILENO));
	ft_error(close(data.fd_pipe[0]));
	ft_error(close(data.fd_pipe[1]));
	data.path_cmd2 = cmd_exist(data.cmd2[0], envp);
	ft_cmd_not_found(data.path_cmd2, data.cmd2);
	ft_error(execve(data.path_cmd2, data.cmd2, NULL));
}

void	parent(t_data data)
{
	int	i;

	ft_error(close(data.fd_pipe[0]));
	ft_error(close(data.fd_pipe[1]));
	ft_error(close(data.infile));
	ft_error(close(data.outfile));
	ft_error(waitpid(data.pid_1, &data.status, 0));
	ft_error(waitpid(data.pid_2, &data.status, 0));
	i = -1;
	while (data.cmd1[++i])
		free(data.cmd1[i]);
	free(data.cmd1);
	i = -1;
	while (data.cmd2[++i])
		free(data.cmd2[i]);
	free(data.cmd2);
}
