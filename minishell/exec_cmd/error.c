/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:19:10 by tguerin           #+#    #+#             */
/*   Updated: 2022/12/14 18:11:24 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd.h"

void	perror_file(char *file_path)
{
	char	*tmp;

	tmp = ft_strjoin("minishell: ", file_path);
	if (!tmp)
	{
		perror("shell");
		return ;
	}
	perror(tmp);
	free(tmp);
}
