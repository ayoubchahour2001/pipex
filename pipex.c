/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahour <achahour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:05:07 by achahour          #+#    #+#             */
/*   Updated: 2025/06/04 00:21:05 by achahour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Child Read from infile to write in pipe and execute Argv[](cmd1)
void	child_process(char **argv, char **envp, int *fd) //Writes to STDOUT (the pipe)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO); //Write end of pipe
	dup2(filein, STDIN_FILENO); //Read end of pipe
	close(fd[0]); //Close pipe read end
	execute(argv[2], envp); //read from the input file and write to the pipe
}

//Parent Read from pipe to write to output and execute Argv[3](cmd2)
void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO); //Duplicate file descriptor "READ END OF PIPE"
	dup2(fileout, STDOUT_FILENO); //Duplicate file descriptor "WRITE END OF PIPE"
	close(fd[1]); //Close the write end of pipe
	execute(argv[3], envp); //read from the input file and write to the output file
}

int	main(int argc, char **argv, char **envp)
{
	int fd[2]; //BECOMES WRITE END OF PIPE FROM FD[1]
	pid_t	pid1;

	if(argc == 5) //You're giving the program 5 arguments totaL
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0); //Wait for process with id to finish, Argument "don't care about capturing the child exit status", 0 Flags
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2); // Print an error message in red to standard error (fd = 2)
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1); // Print the correct usage example to standard output (fd = 1)
	}
	return (0);
}