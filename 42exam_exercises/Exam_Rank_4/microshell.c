#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

static void	put_error(char *err, char *arg)
{
	while (*err)
		write(STDERR_FILENO, err++, 1);
	if (arg)
	{
		while (*arg)
			write(STDERR_FILENO, arg++, 1);
	}
	write(STDERR_FILENO, "\n", 1);
}

static int	next_sep_index(char **argv)
{
	int i = 0;

	while (argv[i] && strcmp("|", argv[i]) && strcmp(";", argv[i]))
		i++;
	return (i);
}

static void	execute_cd(char **argv, int i)
{
	if (i != 2)
		put_error("error: cd: bad arguments", NULL);
	else if (chdir(argv[1]) == -1)
		put_error("error: cd: cannot change directory to", argv[1]);
}

static void	set_pipe_if(int has_pipe, int *fds, int end)
{
	if (!has_pipe)
		return ;
	dup2(fds[end], end);
	close(fds[1]);
	close(fds[0]);
}

static void	execute_cmd(char **argv, int i, char **envp, int saved_stdin)
{
	int 	has_pipe = argv[i] && !strcmp("|", argv[i]);
	int		has_semicolon = argv[i] && !strcmp(";", argv[i]);
	int		fds[2];
	pid_t	pid;

	if (has_pipe)
		pipe(fds);
	pid = fork();
	if (pid == 0)
	{
		set_pipe_if(has_pipe, fds, STDOUT_FILENO);
		argv[i] = NULL;
		execve(argv[0], argv, envp);
		put_error("error: cannot execute", argv[0]);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
	set_pipe_if(has_pipe, fds, STDIN_FILENO);
	if (has_semicolon)
		dup2(saved_stdin, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	i = 0;
	int saved_stdin = dup(STDIN_FILENO);

	(void)argc;
	while (argv[i])
	{
		argv += i + 1;
		i = next_sep_index(argv);
		if (i != 0)
		{
			if (!strcmp("cd", argv[0]))
				execute_cd(argv, i);
			else
				execute_cmd(argv, i, envp, saved_stdin);
		}
	}
	close(saved_stdin);
	return (EXIT_SUCCESS);
}
