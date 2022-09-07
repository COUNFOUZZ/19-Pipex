/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:02:18 by aabda             #+#    #+#             */
/*   Updated: 2022/09/07 15:19:50 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	// char *options[3] = {"ls", "-la", NULL};
	// (void)argc;
	// (void)argv;
	// execve("/bin/ls", options, envp);

	char	**test = path_final(envp);
	int i = 0;
	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}

	return (0);
}
