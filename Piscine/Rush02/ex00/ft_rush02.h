/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:24:36 by vnaud             #+#    #+#             */
/*   Updated: 2022/03/06 18:44:00 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define PATH "numbers.dict"

typedef struct s_dict
{
	char	*value_num;
	char	*value_alpha;
}t_dict;

int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_is_in_charset(char c, char *charset);
void	ft_count_word(char *str, char *charset, int *wordcount);
void	ft_add_word(char **res, char *str, int *size, int index);
void	ft_get_word(char **res, char *str, char *charset, int word_count);
char	**ft_split(char *str, char *charset);
char	*ft_ten_power(int nbr);
char	*ft_strcpy(char *dest, char *src);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_get_type(t_dict *dict, char *nbr);
char	*ft_get_value(t_dict *dict, char *nbr);
int		ft_pattern_three(t_dict *dict, char *nbr);
int		ft_pattern_two(t_dict *dict, char *nbr);
int		ft_pattern_one(t_dict *dict, char *nbr);
int		ft_print(t_dict *dict, char *nbr);
int		ft_count_line(char *path);
t_dict	*ft_upload_dict(t_dict *dict, char *buffer);
t_dict	*ft_dict_entry(char *line);
t_dict	*ft_upload_data(char **res, t_dict *dict, int index);
void	ft_free_dict(t_dict *dict);
int		ft_arg_error(char *str);
int		ft_path_error(char *str);
int		error_line(char *str);
int		double_point(char *str);
int		error_back_slash(char *str, int index);
int		error_double_point(char *str, int index);
t_dict	*ft_parser(char *path);

#endif
