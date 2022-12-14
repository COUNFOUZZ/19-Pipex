/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:37:14 by aabda             #+#    #+#             */
/*   Updated: 2022/09/28 19:14:24 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**find_paths_and_split(char **envp)
{
	char	*envp_path;
	char	**paths;
	int		i;

	if (!envp)
		return (NULL);
	envp_path = NULL;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			envp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			break ;
		}
	}
	paths = ft_split(envp_path, ':');
	if (envp_path)
		free(envp_path);
	return (paths);
}

static char	**paths_add_slash(char **paths)
{
	int		i;

	paths = find_paths_and_split(paths);
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	return (paths);
}

char	*cmd_exist(char	*cmd, char **paths)
{
	char	*cmd_path;
	int		i;

	if (!cmd)
		return (NULL);
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '/')
		{
			if (access(cmd, F_OK | X_OK) == 0)
				return (cmd);
			return (NULL);
		}
	}
	paths = paths_add_slash(paths);
	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}
