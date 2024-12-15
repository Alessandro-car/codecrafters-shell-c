#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		printf("%s: command not found\n", input);
		fflush(stdin);
	}
	return 0;
}
