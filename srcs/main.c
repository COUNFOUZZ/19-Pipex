/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:55:58 by aabda             #+#    #+#             */
/*   Updated: 2022/09/28 14:14:40 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>	// need to be delete

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	initialize_struct(&data, argv);
	if (pipe(data.fd_pipe) == -1)
		return (1);
	data.pid_1 = fork();
	if (data.pid_1 == -1)
		return (printf("Error creating process"));	// need to not use printf
	if (data.pid_1 == 0)
		child1(data, envp);
	else if (data.pid_1 > 0)
	{
		data.pid_2 = fork();
		if (data.pid_2 == -1)
			return (printf("Error creating process"));	// need to not use printf
		if (data.pid_2 == 0)
			child2(data, envp);
		parent(data);
	}
	return (0);
}
