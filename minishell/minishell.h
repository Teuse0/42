/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:19:20 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 20:38:14 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define HERE_DOC_EOL "minishell: warning: here-document at line %d \
delimited by end-of-file (wanted `%s')\n"

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_cmd
{
	char	**args;
	char	*path;
	int		pid;
	int		error_flag;
}		t_cmd;

typedef struct s_redirection
{
	char	*in;
	char	*out;
	int		is_append;
}		t_redirection;

extern int	g_exit_status;

void			signal_cmd(int sig);
void			signal_cmd2(int sig);
int				exec_cmd(t_cmd **cmds, char *lim, char ***envp,
					t_redirection redirection);
char			*cmd_path(char **env, char *cmd, int *error_flag);
void			free_cmds(t_cmd **cmds);
void			here_doc(char *lim, int write_fd);
char			***ft_pars(char *str, char **env);
char			*ft_double_sep(char *str, int i);
char			*ft_simple_sep(char *str, int i);
void			ft_free_lst_cmd(char **lst_cmd);
void			ft_pars_env(char **lst_cmd, char **env);
char			*ft_strjoin_free(char *s1, char *s2);
int				ft_check_dollar(char *str);
int				ft_copy_tmp(char *ret, char *tmp, int size);
int				ft_single_quote_env(char *str, char *ret, int *i, int size);
int				ft_size_malloc(char *str, char **env);
int				ft_check_cmd(char *str);
int				ft_size_str(char *str, int i);
char			*ft_sep(char *str, int i);
int				is_dollar(char *str, int i);
int				ft_check_spaces(char *str);
char			***sep_cmds(char **cmds);
void			free_sep_cmds(char ***sep_cmds);
void			order_redir(char ***raw_cmd);
void			order_heredeocs(char ***raw_cmd);
int				do_useless_heredocs(char ***cmd);
int				do_useless_redir(char ***cmd);
int				remove_trailing_pipes(char ***cmd);
t_cmd			**lst_to_cmd(char **arg, char **env, int *error_flag);
char			*get_lim(char **str);
t_redirection	ft_create_redir(char **str, int is_first, int is_last);
int				exit_(int argc, char **argv, char ***env);
int				parse_and_exec_cmd(char ***env, char *str);
int				get_len_env_var(char *var, char **env);
char			*ft_get_var_env(char *var, char **env);
int				ft_is_cmd(char *arg, char **env, int *error_flag);
int				ft_size_arg(char *str, int i);
int				ft_nbr_args(char *str);
void			ft_free_all(t_cmd **cmds, char **str, char ***raw_cmds);
char			*get_lim(char **str);
char			*ft_strtrim_free(char *s1, char const *set);
char			*ft_change(char *str);
int				is_regular_file(const char *path, int *error_flag);
char			**ft_get_args(char *str);
char			*copy(char *arg, int i);
char			*ft_get_cmd(char *arg, char **env, int *error_flag);
char			*ft_remove_spaces(char *str);
char			***sep_and_reorder(char **lst_cmd, char **str, char **env);
int				ft_size_tab(char *str);
int				is_builtin(char *cmd_name);
int				ft_size_cmd(char *arg);
void			double_increment(int *i, int *j);
void			fake_open(const char *file_name, int is_append);
char			*ft_get_var(char *str, int i, char **env);
void			free_stuff(char *lim, t_cmd **cmds);
void			init_redir(t_redirection *redirection);
int				ft_condition_2(char **cmds, int i, char **env,
					int *error_flag);
int				ft_condition_1(char **cmds, int i, char *cmd);
t_cmd			**ft_lst_heredeoc(char **arg, char **env, int *error_flag,
					char **cmds);
char			**ft_get_sep_cmds(char **arg, int *error_flag, char **env);
char			**ft_get_sep_cmds_2(char **arg, char **env,
					int *error_flag, char **cmds);
int				ft_size_lst(char **arg, int *error_flag, char **env);
int				ft_size_cmds(char **arg, int *error_flag, char **env);
void			ft_free_split(char **tmp);
char			*ft_strjoin_free2(char *s1, char *s2);
t_cmd			*ft_get_lst_heredoc(char *arg, char **env, char *cmd,
					int *error_flag);

#endif
