/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:13:12 by aabda             #+#    #+#             */
/*   Updated: 2022/10/10 11:44:11 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**getcmd(char *s)
{
	if (!s)
		return (NULL);
	return (ft_split(s, ' '));
}

void	ft_error(int ret)
{
	if (ret == -1)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(1);
	}
}

void	ft_cmd_not_found(char *path_cmd, char	**cmd)
{
	if (!path_cmd)
	{
		write(2, "Command not found: ", 19);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, "\n", 1);
		exit(1);
	}
}

void	initialize_struct(t_data *data, char **argv)
{
	data->cmd1 = getcmd(argv[2]);
	data->cmd2 = getcmd(argv[3]);
	data->infile = open(argv[1], O_RDONLY);
	ft_error(data->infile);
	data->outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	ft_error(data->outfile);
}
