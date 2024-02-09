/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:10:08 by tkwak             #+#    #+#             */
/*   Updated: 2024/02/08 17:10:15 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

void	handle_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	print_usage_and_exit(void)
{
	ft_printf("Example: ./pipex infile cmd cmd outfile\n");
	exit(EXIT_FAILURE);
}

void	ft_creat_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		handle_error("pipe: ");
}

int	main(int ac, char **av, char **envp)
{
	int		kernel_pipe_fd[2];
	pid_t	pid;

	if (ac != 5)
		print_usage_and_exit();
	print_error_cmd(envp, av[2]);
	print_error_cmd(envp, av[3]);
	ft_creat_pipe(kernel_pipe_fd);
	pid = fork();
	if (pid < 0)
		handle_error("fork: ");
	else if (pid == 0)
		child_exe(av, kernel_pipe_fd, envp);
	else
	{
		waitpid(pid, NULL, WNOHANG);
		parent_exe(av, kernel_pipe_fd, envp);
	}
	return (0);
}
