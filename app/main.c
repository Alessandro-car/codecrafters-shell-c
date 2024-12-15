#include <stdio.h>
#include <string.h>

int main() {
  // Uncomment this block to pass the first stage
  printf("$ ");
  fflush(stdout);

  // Wait for user input
  while(1) {
		char input[100];
  	fgets(input, 100, stdin);
  	input[strlen(input) - 1] = '\0';
		printf("%s: command not found\n", input);
		printf("$ ");
		fflush(stdout);
		fflush(stdin);
	}
	return 0;
}
