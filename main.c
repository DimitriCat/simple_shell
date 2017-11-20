#include "holberton.h"

int main(void)
{
	char *argv[5], *token, *buffer;
	struct stat statbuff;
	size_t length = 1;
	pid_t child;
	int status, x = 0;

	while (1)
	{
		buffer = getinput();
		token = strtok(buffer, TOK_DELIM);
		do
		{
			argv[x] = _strdup(token);
			x++;
			token = strtok(NULL, TOK_DELIM);
		} while (token != NULL);

		if (argv != NULL && argv[0] != NULL)
		{
			builtin(argv[0]);
			if (stat(argv[0], &statbuff) != 0)
				argv[0] = findpath(argv[0]);
			child = fork();
			if (child < 0)
				perror("Error");

			if (child == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
					perror("Error");
			}
			else
		}
				wait(&status);
		}
		x = 0;
	}
	if (read(STDIN_FILENO, buffer, length))
	{
		free(buffer);
		return (0);
	}
}
