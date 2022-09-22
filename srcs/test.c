#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "../includes/pipex.h"

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

int	main(int argc, char **argv, char **envp)
{
	t_data data;
	char *test[] =  {"ls", "-la", NULL};
	char *test2[] =  {"wc", NULL, NULL};

	data.infile = open(argv[1], O_RDONLY);
	data.outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	pipe(data.fd_pipe);
	data.pid_1 = fork();
	if (data.pid_1 == -1)
	{
		ft_putstr("[CHILD-1]\n");
		ft_putstr("Error creating process");
		return (1);
	}
	else if (data.pid_1 == 0)
	{
		ft_putstr("[CHILD-1]\n");
		dup2(data.infile, STDIN_FILENO);
		dup2(data.fd_pipe[1], STDOUT_FILENO);
		close(data.fd_pipe[0]);
		close(data.fd_pipe[1]);
		data.cmd1 = cmd_exist(argv[2], envp);
		execve(data.cmd1, test, NULL);
	}
	else if (data.pid_1 > 0)
	{
		data.pid_2 = fork();
		if (data.pid_2 == -1)
		{
			ft_putstr("[CHILD-2]\n");
			ft_putstr("Error creating process");
			return (1);
		}
		if (data.pid_2 == 0)
		{
			ft_putstr("[CHILD-2]\n");
			dup2(data.fd_pipe[0], STDIN_FILENO);
			dup2(data.outfile, STDOUT_FILENO);
			close(data.fd_pipe[0]);
			close(data.fd_pipe[1]);
			data.cmd2 = cmd_exist(argv[3], envp);
			execve(data.cmd2, test2, NULL);
		}
		ft_putstr("[PARENT]\n");
		close(data.fd_pipe[0]);
		close(data.fd_pipe[1]);
		close(data.infile);
		close(data.outfile);
		waitpid(data.pid_1, &data.status, 0);
		waitpid(data.pid_2, &data.status, 0);
	}
	return (0);
}
