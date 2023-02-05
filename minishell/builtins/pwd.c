/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:48:56 by tguerin           #+#    #+#             */
/*   Updated: 2023/01/31 20:36:01 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	pwd(int argc, char **argv, char ***env)
{
	char	pwd[4097];

	(void)argc;
	(void)argv;
	(void)env;
	getcwd(pwd, 4096);
	printf("%s\n", pwd);
	return (EXIT_SUCCESS);
}
