#include "get_next_line_bonus.h"
#include "get_next_line_utils_bonus.c"
#include "get_next_line_bonus.c"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd); // assume this is declared

//Readng a newline and swtiching to read another opened file
/* int	main(void)
{
	int		fd[4];
	char	*files[4] = {"filename.txt", "filename2.txt", "filename3.txt", "filename4.txt"};
	char	*line;
	int		done[4] = {0, 0, 0, 0}; // track which fd is done
	int		active_fds = 4;
	int		i;

	// Open files
	for (i = 0; i < 4; i++)
	{
		fd[i] = open(files[i], O_RDONLY);
		if (fd[i] == -1)
		{
			perror("Error opening file");
			done[i] = 1;
			active_fds--;
		}
		else
			printf("Opened %s (fd = %d)\n", files[i], fd[i]);
	}

	// Alternate reading lines from each fd
	while (active_fds > 0)
	{
		for (i = 0; i < 4; i++)
		{
			if (done[i])
				continue;

			line = get_next_line(fd[i]);
			if (line)
			{
				printf("fd %d (%s): %s", fd[i], files[i], line);
				free(line);
			}
			else
			{
				printf("End of file for %s (fd = %d)\n", files[i], fd[i]);
				close(fd[i]);
				printf("Closed %s\n", files[i]);
				done[i] = 1;
				active_fds--;
			}
		}
	}

	printf("********** ALL FILES READ **********\n");
	return (0);
} */

//Reading from an invalid fd, changed filename3 to a non-existing file
int	main(void)
{
	int		fd[4];
	char	*files[4] = {"filename.txt", "filename2.txt", "non-existent.txt", "filename4.txt"};
	char	*line;
	int		done[4] = {0, 0, 0, 0}; // track which fd is done
	int		active_fds = 4;
	int		i;

	// Open files
	for (i = 0; i < 4; i++)
	{
		fd[i] = open(files[i], O_RDONLY);
		if (fd[i] == -1)
		{
			perror("Error opening file");
			done[i] = 1;
			active_fds--;
		}
		else
			printf("Opened %s (fd = %d)\n", files[i], fd[i]);
	}

	// Alternate reading lines from each fd
	while (active_fds > 0)
	{
		for (i = 0; i < 4; i++)
		{
			if (done[i])
				continue;

			line = get_next_line(fd[i]);
			if (line)
			{
				printf("fd %d (%s): %s", fd[i], files[i], line);
				free(line);
			}
			else
			{
				printf("End of file for %s (fd = %d)\n", files[i], fd[i]);
				close(fd[i]);
				printf("Closed %s\n", files[i]);
				done[i] = 1;
				active_fds--;
			}
		}
	}

	printf("********** ALL FILES READ **********\n");
	return (0);
}