/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:18 by ychng             #+#    #+#             */
/*   Updated: 2023/10/31 21:48:03 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "sys_headers.h"
# include "libft.h"

void	exit_program(char *msg);
void	process_input(int argc, char **argv, char **envp);

#endif