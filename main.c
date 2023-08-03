#include "get_next_line.h"

void	printfLine(int	n, int *fd)
{
	char	*line = "abc";

	line = get_next_line(fd[n]);
	printf("%s\n", line);
	if (line)
		free(line);
}

int main(void)
{
	int		fd[10];

	//signal(SIGSEGV, sigsegv); int fd[4];
	fd[0] = open("mainteset/41_with_nl", O_RDWR);
	fd[1] = open("mainteset/42_with_nl", O_RDWR);
	fd[2] = open("mainteset/43_with_nl", O_RDWR);
	printfLine(0, fd);
	printfLine(1, fd);
	printfLine(2, fd);
	printfLine(0, fd);
	printfLine(1, fd);
	printfLine(2, fd);
	printfLine(0, fd);
	printfLine(1, fd);
	printfLine(2, fd);
	return 0;
}