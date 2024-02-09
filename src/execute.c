/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:24:25 by tkwak             #+#    #+#             */
/*   Updated: 2024/02/09 14:28:08 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free2d_n_exit(char **str)
{
	free_2d(str);
	exit(EXIT_FAILURE);
}

void	handle_error_dup2(int *kernel_pipe_fd)
{
	perror("dup2: ");
	close(kernel_pipe_fd[0]);
	close(kernel_pipe_fd[1]);
	exit(EXIT_FAILURE);
}

void	exec(char *cmd, char **envp)
{
	char	**cmd_div_space;
	char	*path;

	cmd_div_space = ft_split(cmd, ' ');
	if (!cmd_div_space)
		handle_error("ft_split: ");
	if (!cmd_div_space[0])
		free2d_n_exit(cmd_div_space);
	path = check_cmd_in_path(envp, cmd_div_space[0]);
	if (!path)
		free2d_n_exit(cmd_div_space);
	execve(path, cmd_div_space, envp);
	perror("execve: ");
	if (path)
		free(path);
	free_2d(cmd_div_space);
	exit (EXIT_FAILURE);
}

void	child_exe(char **av, int *kernel_pipe_fd, char **envp)
{
	int	input_fd;

	input_fd = open_file(av[1], 0);
	if (input_fd == -1)
		handle_error("open_file: ");
	if (dup2(input_fd, STDIN_FILENO) == -1)
	{
		close(input_fd);
		handle_error_dup2(kernel_pipe_fd);
	}
	close(input_fd);
	if (dup2(kernel_pipe_fd[1], STDOUT_FILENO) == -1)
		handle_error_dup2(kernel_pipe_fd);
	close(kernel_pipe_fd[0]);
	exec(av[2], envp);
	handle_error("exec: ");
	return ;
}

void	parent_exe(char **av, int *kernel_pipe_fd, char **envp)
{
	int	output_fd;

	output_fd = open_file(av[4], 1);
	if (output_fd == -1)
		handle_error("open_file: ");
	if (dup2(output_fd, STDOUT_FILENO) == -1)
	{
		close(output_fd);
		handle_error_dup2(kernel_pipe_fd);
	}
	close(output_fd);
	if (dup2(kernel_pipe_fd[0], STDIN_FILENO) == -1)
		handle_error_dup2(kernel_pipe_fd);
	close(kernel_pipe_fd[1]);
	exec(av[3], envp);
	handle_error("exec: ");
	return ;
}
