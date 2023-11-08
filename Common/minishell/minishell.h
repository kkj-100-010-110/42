/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:20:04 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/30 21:49:40 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Libs
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <fcntl.h>
# include <termios.h>
/*
** Macros to define quotes
*/
# define D_QUOTE '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"

/*
** Macros to define some prompt colors
*/
# define CYAN "\001\033[1;36m\002"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"

/*
** Macros to define some messages error
*/
# define ERROR_PIPE "minishell: syntax error near unexpected token `|'\n"
# define ERROR_DIR "No such file or directory\n"
# define ERROR_HOME "minishell: cd: HOME not set\n"
# define ERROR_CMD "command not found"

/*
** Global variable to return in 'echo $?'
*/
int	g_ret_number;

/*
** Struct for environment variables
*/
typedef struct s_env
{
	char	**env;
	int		len;
	char	**key;
	char	**content;
	int		index;
}			t_env;

/*
** Struct to help split_cmd.c
*/
typedef struct s_split
{
	int		n_comand;
	int		ini;
	int		len;
	int		q;
	int		qtt_pipe;
}			t_split;

/*
** Struct to help token.c
*/
typedef struct s_token
{
	char	*to_print;
	char	quote;
	char	*end;
	char	*new;
	int		i;
	int		init;
	int		len;
	int		posic;
}			t_token;

typedef struct s_items
{
	bool	is_builtin;
	bool	has_flag;
	int		is_append;
	int		out_fd;
	int		in_fd;
	int		num_tokens;
	int		c;
	char	quote;
	char	*line;
	char	*line_read;
	char	*name_file;
	char	*error_name_file;
	char	*home;
	char	*commands[50];
	char	*token_aux;
	char	**tokens;
	char	**path;
	t_env	env_aux;
	t_env	env;
	t_split	split;
	t_token	token;
}			t_items;

/*
** Minishell functions
*/

/*
**
*/

void	del_c(void);
/*
** builtins.c
*/
void	is_builtin(char *cmd, t_items *items);
void	run_builtin(t_items *items);

/*
** find_env.c
*/
char	*find_env(t_items *items, char *needle);

/*
** ft_cd.c
*/
int		ft_cd(t_items *items);
bool	there_is_home(t_items *items);
/*
** ft_echo.c
*/
void	ft_echo(t_items *items);
void	print_echo(t_items *items, char *mini_tokens_i);

/*
** ft_env.c
*/
void	ft_env(t_items *items);
void	create_env(t_items *items, char **my_env);
void	len_env(t_items *items);
void	init_struct_env(t_items *items);

/*
** ft_exit.c
*/
void	ft_exit(t_items *items);
void	free_line(char *line_read);
void	free_char_array(char **array);
void	free_char_array2(char **array);

/*
** ft_export.c
*/
void	ft_export(t_items *items);
void	verify_if_env_exists(t_items *items, char **env_aux, int i);
void	add_env(t_items *items, char *new_key, char *new_content);

/*
** ft_pwd.c
*/
void	ft_pwd(t_items *items);
char	*get_cwd_buf(void);

/*
** ft_unset.c
*/
void	ft_unset(t_items *items);
void	rm_env(t_items *items);
void	alloc_env_aux(t_items *items);

/*
** init_path.c
*/
int		init_path(t_items *items);

/*
** main.c
*/
int		main(int argc, char **argv, char **envp);
void	initialize(t_items *items, int argc, char **argv, char **envp);
void	get_line(t_items *items);
char	*create_prompt(void);

/*
** redir_in.c
*/
void	redirect_in(t_items *items, int j);
char	**double_redir(t_items *items, char **file, int j);
void	read_until(char *end);
char	*new_command(int i, char **str);

/*
** redir_out.c
*/
void	redirect_out(t_items *items, int j);
void	simple_redir_out(t_items *items, int j, int flags);
int		find_char(char *string, char needle);

/*
** run_pipe_aux.c
*/
int		file_descriptor_handler(int in, int out);
void	spaces_in_pipe(t_items *items, int i, char *command);
void	execve_error(t_items *items);

/*
** run_pipe.c
*/
void	run_commands(t_items *items);
void	run_commands_aux(t_items *items);
void	action(t_items *items);
void	exec_process(t_items *items, int in, int out);
void	ft_execve_pipe(t_items *items, int i, char *command);

/*
** signal.c
*/
void	run_signals(int sig);
void	restore_prompt(int sig);
void	ctrl_c(int sig);
void	back_slash(int sig);

/*
** split_cmd.c
*/
void	split_cmd(t_items *items, char *in, int i);
void	init_split_struct(t_items *items);
char	*clean_spaces(char *in);
int		count_pipe(t_items *items, char *in, int i);

/*
** token.c
*/
void	tokenizer(t_items *items);
void	tokenizer_clean_quotes(t_items *items, char *in, int i, int c);
int		tokenizer_find_char(char *string, char needle);

/*
** token_utils.c
*/
void	get_home_sign(t_items *items, t_token *tk);
void	get_dollar_sign(t_items *items, t_token *tk);
t_token	*init_tk(void);
void	free_tk(t_token *tk);
void	finish_tokenizer(t_items *items, t_token *tk);

// libft in utils.c
char	*ft_itoa(int n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *restrict dst,
			const char *restrict src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
