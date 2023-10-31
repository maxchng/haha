/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:23 by ychng             #+#    #+#             */
/*   Updated: 2023/10/31 21:47:56 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	exit_program(char *msg)
{
	write(STDOUT_FILENO, msg, ft_strlen(msg));
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		exit_program("please write in the proper format:"
			" ./pipex file1 cmd1 cmd2 file2.\n");
	}
	process_input(argc, argv, envp);
}

// int		i;
// char	*path;
// char	*bin_path;
// char	*command;

// command = "ls";
// i = -1;
// while (envp[++i])
// {
// 	if (ft_strncmp(envp[i], "PATH=", 5) != 0)
// 		continue ;
// 	path = envp[i] + 5;
// 	bin_path = ft_strtok(path, ":");
// 	while (bin_path != NULL)
// 	{
// 		bin_path = ft_strjoin(bin_path, command, "/");
// 		if (access(bin_path, F_OK) == 0)
// 		{
// 			printf("file exist here: %s\n", bin_path);
// 		}
// 		bin_path = ft_strtok(NULL, ":");
// 	}
// }