/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:00 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/22 12:03:45 by acalvo4          ###   ########.fr       */
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
	char	*tmp2;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK | X_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	write(2, ": command not found\n", 20);
	exit(EXIT_FAILURE);
	return (0);
}
