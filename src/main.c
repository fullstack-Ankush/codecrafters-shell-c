#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  char command[100];
  fgets(command ,100,stdin);
  command[strlen(command)-1] = '\0';
  printf("%s:command not found \n");

  // TODO: Uncomment the code below to pass the first stage
  // printf("$ ");



  return 0;
}
