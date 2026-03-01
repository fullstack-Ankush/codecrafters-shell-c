#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    if(strncmp(command,"echo ",5) == 0){
      printf("%s\n",command+5);
      continue;
    }
    if(strncmp(command,"type ",5) == 0){
      char *cmd = command + 5;
      if(strcmp(cmd,"echo")==0 || strcmp(cmd,"type")==0 || strcmp(cmd,"exit")== 0) {
        printf("%s is a shell builtin\n",cmd);
        continue;
      }
      else{
        // Search for command in PATH
        char *path = getenv("PATH");
        if(path == NULL) {
          printf("%s: not found\n",cmd);
          continue;
        }
        
        char path_copy[1000];
        strcpy(path_copy, path);
        
        char *dir = strtok(path_copy, ":");
        int found = 0;
        
        while(dir != NULL) {
          char full_path[256];
          snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);
          
          // Check if file exists and is executable
          if(access(full_path, X_OK) == 0) {
            printf("%s is %s\n", cmd, full_path);
            found = 1;
            break;
          }
          dir = strtok(NULL, ":");
        }
        
        if(!found) {
          printf("%s: not found\n",cmd);
        }
        continue;
      }
    } 
    printf("%s: command not found \n",command);
  }
  

  return 0;
}
