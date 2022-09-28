/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:11:05 by aabda             #+#    #+#             */
/*   Updated: 2022/09/28 17:08:59 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

void	child1(t_data data, char **envp)
{
	dup2(data.infile, STDIN_FILENO);
	dup2(data.fd_pipe[1], STDOUT_FILENO);
	close(data.fd_pipe[0]);
	close(data.fd_pipe[1]);
	data.path_cmd1 = cmd_exist(data.cmd1[0], envp);
	execve(data.path_cmd1, data.cmd1, NULL);
}

void	child2(t_data data, char **envp)
{
	dup2(data.fd_pipe[0], STDIN_FILENO);
	dup2(data.outfile, STDOUT_FILENO);
	close(data.fd_pipe[0]);
	close(data.fd_pipe[1]);
	data.path_cmd2 = cmd_exist(data.cmd2[0], envp);
	execve(data.path_cmd2, data.cmd2, NULL);
}

void	parent(t_data data)
{
	close(data.fd_pipe[0]);
	close(data.fd_pipe[1]);
	close(data.infile);
	close(data.outfile);
	waitpid(data.pid_1, &data.status, 0);
	waitpid(data.pid_2, &data.status, 0);
}
