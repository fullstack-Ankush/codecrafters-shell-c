#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
#define PATH_SEP ";"
#else
#define PATH_SEP ":"
#endif

int find_file(char *arg, char *path_env, int verbose);

int main(int argc, char *argv[]) {
  char cmd[100];
  char *path_env;
  char input[999];
  char tmp_input[999];
  char *tok;

  path_env = getenv("PATH");
  setbuf(stdout, NULL);
  while (1) {
    printf("$ ");
    fgets(input, 999, stdin);
    input[strlen(input) - 1] = '\0';
    strcpy(tmp_input, input);
    tok = strtok(tmp_input, " ");
    if (strcmp(tok, "exit") == 0)
      return (0);
    else if (strcmp(tok, "type") == 0) {
      tok = strtok(NULL, " ");
      if (strcmp(tok, "echo") == 0 || strcmp(tok, "exit") == 0 ||
          strcmp(tok, "type") == 0) {
        printf("%s is a shell builtin\n", tok);
        continue;
      }
      find_file(tok, path_env, 1);
    } else if (strcmp(tok, "echo") == 0) {
      tok = strtok(NULL, " ");
      while (tok != NULL) {
        printf("%s ", tok);
        tok = strtok(NULL, " ");
      }
      printf("\n");
    } else if (find_file(tok, path_env, 0))
      system(input);
    else
      printf("%s: command not found\n", tmp_input);
  }