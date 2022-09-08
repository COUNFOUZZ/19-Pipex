/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:02:18 by aabda             #+#    #+#             */
/*   Updated: 2022/09/08 14:29:31 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	char *options[3] = {"ls", "-la", NULL};
	(void)argc;
	(void)argv;
	execve("/bin/ls", options, envp);

	printf("%s", path_final("ls", envp));

	return (0);
}
