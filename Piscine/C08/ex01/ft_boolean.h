/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:07:51 by broy              #+#    #+#             */
/*   Updated: 2022/03/07 22:11:15 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN_MSG	"I have even number of arguments.\n"
# define ODD_MSG	"I have odd number of arguments.\n"
# define EVEN(x)	x % 2 == 0
# define SUCCES	0
# define TRUE		1
# define FALSE		0

typedef int	t_bool;

#endif
