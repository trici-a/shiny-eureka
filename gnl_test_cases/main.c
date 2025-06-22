#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"
#include "get_next_line.c"

//To check for opening the file
int main()
{
	int		fd;
	char	*line;
	int		i;

	fd = open("filename.txt", O_RDONLY);
	if (fd == -1) // Always check if open failed
    {
        perror("Error opening file");
        return (1);
    }
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d:%s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
	printf("\n**********THE END.**********\n");
	return (0);
}

//Read on an invalid fd, do not need to open the file
/* int main()
{
	int		fd;
	char	*line;
	int		i;

	fd = 654;
	i = 0;
	if (fd == -1) // Always check if open failed
    {
        perror("Error opening file");
        return (1);
    }
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	printf("\n**********THE END.**********\n");
	return (0);
} */

//Read on stdin
/* int main()
{
	int		fd;
	char	*line;
	int		i;

	fd = 0; //stdin = 0, stdio = 1, stderr = 2
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	printf("\n**********THE END.**********\n");
	return (0);
} */
//Long line
/* int main()
{
	int		fd;
	char	*line;
	int		i;

	fd = open("file_longline.txt", O_RDONLY);
	i = 0;
	if (fd == -1) // Always check if open failed
    {
        perror("Error opening file");
        return (1);
    }
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	printf("\n**********THE END.**********\n");
	return (0);
} */

//Short line
/* int main()
{
	int		fd;
	char	*line;
	int		i;

	fd = open("file_shortline.txt", O_RDONLY);
	i = 0;
	if (fd == -1) // Always ch
	eck if open failed
    {
        perror("Error opening file");
        return (1);
    }
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	printf("\n**********THE END.**********\n");
	return (0);
} */
//Empty
/* int main()
{
	int		fd;
	char	*line;
	int		i;

	fd = open("file_empty.txt", O_RDONLY);
	i = 0;
	if (fd == -1) // Always check if open failed
    {
        perror("Error opening file");
        return (1);
    }
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	printf("\n**********THE END.**********\n");
	return (0);
} */