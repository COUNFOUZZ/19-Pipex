#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data data;
	data.cmd1 = getcmd(argv[2]);
	data.cmd2 = getcmd(argv[3]);
	data.infile = open(argv[1], O_RDONLY);
	data.outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipe(data.fd_pipe) == -1)
		return (1);
	data.pid_1 = fork();
	if (data.pid_1 == -1)
	{
		printf("[CHILD-1]\n");
		printf("Error creating process");
		return (1);
	}
	else if (data.pid_1 == 0)
	{
		// printf("[CHILD-1]\n");
		dup2(data.infile, STDIN_FILENO);
		dup2(data.fd_pipe[1], STDOUT_FILENO);
		close(data.fd_pipe[0]);
		close(data.fd_pipe[1]);
		data.path_cmd1 = cmd_exist(data.cmd1[0], envp);
		execve(data.path_cmd1, data.cmd1, NULL);
	}
	else if (data.pid_1 > 0)
	{
		data.pid_2 = fork();
		if (data.pid_2 == -1)
		{
			// printf("[CHILD-2]\n");
			printf("Error creating process");
			return (1);
		}
		if (data.pid_2 == 0)
		{
			// printf("[CHILD-2]\n");
			dup2(data.fd_pipe[0], STDIN_FILENO);
			dup2(data.outfile, STDOUT_FILENO);
			close(data.fd_pipe[0]);
			close(data.fd_pipe[1]);
			data.path_cmd2 = cmd_exist(data.cmd2[0], envp);
			execve(data.path_cmd2, data.cmd2, NULL);
		}
		// printf("[PARENT]\n");
		close(data.fd_pipe[0]);
		close(data.fd_pipe[1]);
		close(data.infile);
		close(data.outfile);
		waitpid(data.pid_1, &data.status, 0);
		waitpid(data.pid_2, &data.status, 0);
	}
	return (0);
}
