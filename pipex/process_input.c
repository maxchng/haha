/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:09:06 by ychng             #+#    #+#             */
/*   Updated: 2023/10/31 22:00:50 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	process_input(int argc, char **argv, char **envp)
{
	int		redirect_input_fd;
	char	**cmd_token;

	redirect_input_fd = open(argv[1], O_RDONLY);
	if (redirect_input_fd == -1)
		exit_program("stdin file doesn't exist.\n");
	dup2(redirect_input_fd, STDIN_FILENO);
	cmd_token = ft_split(argv[2], " "); // MIGHT NEED TO HANDLE TAB




	int		i;
	char	*path;
	char	*bin_path;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) != 0)
			continue ;
		path = envp[i] + 5;
		bin_path = ft_strtok(path, ":");
		while (bin_path != NULL)
		{
			bin_path = ft_strjoin(bin_path, cmd_token[0], "/");
			if (access(bin_path, F_OK) == 0)
			{
				cmd_token[0] = bin_path;
				execve(bin_path, cmd_token, NULL);
			}
			bin_path = ft_strtok(NULL, ":");
		}
	}
}
