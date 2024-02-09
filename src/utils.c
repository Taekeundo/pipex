/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:11:13 by tkwak             #+#    #+#             */
/*   Updated: 2024/02/08 10:11:45 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int in_or_out)
{
	int	res;

	res = 0;
	if (in_or_out == 0)
		res = open(file, O_RDONLY);
	else if (in_or_out == 1)
		res = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (res < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (res);
}

char	**save_all_env_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(&envp[i][ft_strlen("PATH=")], ':'));
		i++;
	}
	perror("save_all_env_paths: ");
	exit(EXIT_FAILURE);
}

char	*convert_command_absolute_path(char **path_array, int i, char *command)
{
	char	*part_path;
	char	*absolute_path;

	part_path = ft_strjoin(path_array[i], "/");
	if (part_path == NULL)
	{
		perror("ft_strjoin: ");
		return (NULL);
	}
	absolute_path = ft_strjoin(part_path, command);
	free(part_path);
	if (absolute_path == NULL)
	{
		perror("ft_strjoin: ");
		return (NULL);
	}
	return (absolute_path);
}

char	*check_cmd_in_path(char **envp, char *command)
{
	char	**path_array;
	char	*path;
	int		i;

	path_array = save_all_env_paths(envp);
	i = 0;
	while (path_array[i] != NULL)
	{
		if (command[0] != '/')
			path = convert_command_absolute_path(path_array, i, command);
		else
			path = ft_strdup(command);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
		{
			free_2d(path_array);
			return (path);
		}
		free(path);
		i++;
	}
	free_2d(path_array);
	return (NULL);
}

void	print_error_cmd(char **envp, char *command)
{
	char	*path_buf;
	char	**buf_command;

	buf_command = ft_split(command, ' ');
	if (!buf_command[0])
	{
		free_2d(buf_command);
		return ;
	}
	path_buf = check_cmd_in_path(envp, buf_command[0]);
	if (!path_buf)
	{
		if (errno == 2)
			ft_printf("%s: command not found\n", buf_command[0]);
		else
			perror("buf_command[0]: ");
	}
	free_2d(buf_command);
	free(path_buf);
	return ;
}
