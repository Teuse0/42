/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:11:32 by tguerin           #+#    #+#             */
/*   Updated: 2023/01/24 20:06:56 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>

int		ft_putenv(char ***env, const char *s);
int		cd(int argc, char **argv, char ***env);
int		echo(int argc, char **argv, char ***env);
int		env(int argc, char **argv, char ***env);
int		export(int argc, char **argv, char ***env);
int		pwd(int argc, char **argv, char ***env);
int		unset(int argc, char **argv, char ***env);

#endif
