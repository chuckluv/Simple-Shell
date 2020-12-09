#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128

char prompt[] = "> ";
char delimiters[] = " \t\r\n";
extern char **environ;



int main() {
    // Stores the string typed into the command line.
    char command_line[MAX_COMMAND_LINE_LEN];
    char cmd_bak[MAX_COMMAND_LINE_LEN];
  
    // Stores the tokenized command line input.
    char *arguments[MAX_COMMAND_LINE_ARGS];
  char cwd[100];
    while (true) {
      
        do{ 
            // Print the shell prompt.
            getcwd(cwd, sizeof(cwd));
            printf("%s%s", cwd,prompt);
            fflush(stdout);

            // Read input from stdin and store it in command_line. If there's an
            // error, exit immediately. (If you want to learn more about this line,
            // you can Google "man fgets")
        
            if ((fgets(command_line, MAX_COMMAND_LINE_LEN, stdin) == NULL) && ferror(stdin)) {
                fprintf(stderr, "fgets error");
                exit(0);
            }
 
        }while(command_line[0] == 0x0A);  // while just ENTER pressed

      
        // If the user input was EOF (ctrl+d), exit the shell.
        if (feof(stdin)) {
            printf("\n");
            fflush(stdout);
            fflush(stderr);
            return 0;
        }
      /*
      int i;
      int pos = 0;
      char arg[MAX_COMMAND_LINE_ARGS];
        for(i=0; i< MAX_COMMAND_LINE_LEN;i++){
          if(command_line[i] != 0x20 && command_line[i] != 0x00){
            strcat(arg[pos],command_line[i]);
          }
          else if(command_line[i] == 0x20 && arg[pos] != NULL){
            arguments[pos] = arg[pos];
            pos++;
          } else{break;}
        }
      int k=0;
      while(arguments[k]){
        printf("%s - ", arguments[k]);
        
      }
      */
        // TODO:
        // 
        
			  // 0. Modify the prompt to print the current working directory
			  
			
        // 1. Tokenize the command line input (split it on whitespace)
        arguments[0]=strtok(command_line, delimiters);
        
        int i =0;
        while(arguments[i] != NULL){
          arguments[++i] = strtok(NULL, delimiters);
        }
      int j;
      
      char cd[]="cd", pwd[]="pwd", echo[]="echo",exit[]="exit",env[]="env",setenv[]="setenv";
        for(j = 0; j<i; j++){
          if (strcmp(arguments[j],cd)==0){
            printf("CD worked\n");
          }
          if (strcmp(arguments[j],pwd)==0){
            printf("pwd worked\n");
          }
          if (strcmp(arguments[j],echo)==0){
            printf("echo worked\n");
          }
          if (strcmp(arguments[j],exit)==0){
            printf("exit worked\n");
          }
          if (strcmp(arguments[j],env)==0){
            printf("env worked\n");
          }
          if (strcmp(arguments[j],setenv)==0){
            printf("setenv worked\n");
          }
        }
      
        // 2. Implement Built-In Commands
        
    
        // 3. Create a child process which will execute the command line input

  
        // 4. The parent process should wait for the child to complete unless its a background process
      
      
        // Hints (put these into Google):
        // man fork
        // man execvp
        // man wait
        // man strtok
        // man environ
        // man signals
        
        // Extra Credit
        // man dup2
        // man open
        // man pipes
    }
    // This should never be reached.
    return -1;
}