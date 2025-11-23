#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int input_fd = -1;
int output_fd = -1;

void close_fd()
{
	if (input_fd > -1)
		close(input_fd);
	if (output_fd > -1)
		close(output_fd);
}

void handle_error(const char *msg)
{
	perror(msg);
	close_fd();
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	ssize_t bytes_read, bytes_written;
	char buffer[1024] = {0,};

	input_fd = open("test.txt", O_RDONLY);
	if (input_fd == -1)
		handle_error("input_fd open error");

	output_fd = open("test_copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		handle_error("output_fd open error");

	while ((bytes_read = read(input_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(output_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
			handle_error("read");
	}

	close_fd();

	return 0;
}
