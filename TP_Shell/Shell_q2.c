#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100



void executeCode(const char *cmd){
	pid_t pid, waitPid;
	int status;
	
	pid = fork();
	
	if (pid == 0){ //child's code
		
		execlp(cmd, cmd, (char *)NULL);
		perror("enseash %");//Error if the child don't go to the command program's
		exit(EXIT_FAILURE);
	}
	else if (pid < 0){ //Error during child creation
		perror("enseash %");
	}
	else{ //Father's code
		do{
			waitPid = waitpid(pid, &status, WUNTRACED);
		} 
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

int main(void){
	char entete[] = "$ ./enseash \nBienvenue dans le SHELL ENSEA \nPour quitter, tapez 'exit'! \n";
	int length = sizeof(entete)-1;
	write(1,entete,length);
	
	char bashLine[] = "./enseash ❤😸❤ >";
	length = sizeof(bashLine)-1;
	
	char input[MAX_COMMAND_LENGTH];
	
	while(1){
		write(1,bashLine,length);
		ssize_t bytesRead = read(1, input, MAX_COMMAND_LENGTH);
		
		input[strcspn(input,"\n")]=0;//Erase the new line entry
		
		executeCode(input);
	}
	return(EXIT_SUCCESS);
}


	
