/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahour <achahour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:05:18 by achahour          #+#    #+#             */
/*   Updated: 2025/06/04 01:39:48 by achahour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* A simple error displaying function. */
void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

/* Function that will look for the path line inside the environment, will
 split and test each command path and then return the right one. */
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	// 
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0) // Find the environement variable that countain system PATH, the function look inside envp and check if PATH appears in the first 4 characters
		i++; //each time it doesn't match we move to the next string, JUST TO FOUND ENVP[] STOP LOOP
	paths = ft_split(envp[i] + 5, ':'); //Pointer to string, we using function split and adding 5 to skipping PATH=
	i = 0;
	while (paths[i]) //Find the correct path of a command like: ls, grep ..
	{
		part_path = ft_strjoin(paths[i], "/"); // building the beginning of the full command path by adding /
		path = ft_strjoin(part_path, cmd); //Adding the command name to path (We atah the command name)
		free(part_path); //frees the memory of the strings you made
		if (access(path, F_OK) ==0 ) //if it exists return this path, if not go to next folder
			return (path);
		free(path); //frees the memory of the strings you made
		i++; //loop conitnue
	}
	i = -1; //using -1 because work with pre-increment ++i
	while (paths[++i]) //starting loop because ++i becomes 0,
		free(paths[i]); 
	free(paths); //Free the array itself
	return (0);
}

/* Function that will read input from the terminal and return line. */
int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	return (r);
}

/* Function that take the command and send it to find_path before executing it. */
void	execute(char *argv, char **envp)
{
	char	**cmd;
	int	i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' '); /// Split the command and its arguments
	path = find_path(cmd[0], envp); // Get the full path of the command
	if (!path) // If no valid path is found
	{
		while(cmd[++i]) // If no valid path is found
			free(cmd[i]); //Free memory and show error
		free(cmd);
		error(); // show error
	}
	if (execve(path, cmd, envp) == -1) // run command, and if it fails return -1, it goes to error
		error();
}