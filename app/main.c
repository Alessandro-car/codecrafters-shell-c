#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum {
	false, true
} bool;

int is_executable(const char *path) { return access(path, X_OK) == 0; }

char *find_in_path(const char *command) {
  char *path_env = getenv("PATH");
  if (path_env == NULL) {
    return NULL;
  }
  char *path_copy = strdup(path_env);
  char *dir = strtok(path_copy, ":");
  static char full_path[1024];
  while (dir != NULL) {
    snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
    if (is_executable(full_path)) {
      free(path_copy);
      return full_path;
    }
    dir = strtok(NULL, ":");
  }
  free(path_copy);
  return NULL;
}

int main() {
		// Wait for user input
	while(1) {

		printf("$ ");
		fflush(stdout);
		char input[100];
  	fgets(input, 100, stdin);
  	input[strlen(input) - 1] = '\0';
		if (strcmp(input, "exit 0") == 0) {
				exit(0);
		}
		if (strncmp(input, "echo", strlen("echo")) == 0) {
			printf("%s\n", input + strlen("echo") + 1);
			continue;
		}

		if (strncmp(input, "type", strlen("type")) == 0) {
			char *command = input + strlen("type") + 1;
			if(strncmp(command, "echo", strlen("echo")) == 0||
				strncmp(command, "type", strlen("type")) == 0||
				strncmp(command, "exit", strlen("exit")) == 0)
			{
				printf("%s is a shell builtin\n", input + strlen("type") + 1);
			} else {
				char *path = find_in_path(command);
				if (path) {
					printf("%s is %s\n", command, path);
				} else {
					printf("%s: not found\n", command);
				}
			}
			continue;
		}


		printf("%s: command not found\n", input);
		fflush(stdin);
	}
	return 0;
}
