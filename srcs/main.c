/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:55:58 by aabda             #+#    #+#             */
/*   Updated: 2022/09/29 12:32:53 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc == 5)
	{
		initialize_struct(&data, argv);
		ft_error(pipe(data.fd_pipe));
		data.pid_1 = fork();
		ft_error(data.pid_1);
		if (data.pid_1 == 0)
			child1(data, envp);
		else if (data.pid_1 > 0)
		{
			data.pid_2 = fork();
			ft_error(data.pid_2);
			if (data.pid_2 == 0)
				child2(data, envp);
			parent(data);
		}
	}
	else
		write(2, "Invalid number of arguments\n", 28);
	return (0);
}
