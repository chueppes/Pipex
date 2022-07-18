/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:00 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/18 09:36:02 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char **envp, char *cmd)
{
	char	*env_path;
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path)
		{
			env_path = ft_strtrim(env_path, "PATH=");
			break ;
		}
		i++;
	}
	path = ft_split(&env_path[i], ':');
	return (test_path(path, cmd));
}

char	*test_path(char **path, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(path[i], cmd);
		if (access(tmp, F_OK | X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (ft_put(ERROR_CMD));
}
