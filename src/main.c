#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  char command[100];
  while(1){
    printf("$ ");
    fgets(command ,100,stdin);
    command[strlen(command)-1] = '\0';
    if(strcmp(command,"exit") == 0)
      exit(0);
    printf("%s: command not found \n",command);


  }
  

  // TODO: Uncomment the code below to pass the first stage



  return 0;
}
