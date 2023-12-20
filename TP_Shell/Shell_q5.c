#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 100



long executeCode(const char *cmd){
	pid_t pid, waitPid;
	int status;
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC,&start);
	
	pid = fork();
	
	if (pid == 0){ //child's code
		
		//For test purpose
		//sleep(1);
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
	
	clock_gettime(CLOCK_MONOTONIC,&end);
	long elapsed_time = (end.tv_sec -start.tv_sec)*1000 + (end.tv_nsec -start.tv_nsec)/1000000;
	return elapsed_time;
}

void printPrompt(int status, long elapsed_time){
	char buffer[50];
	int len;
	
	if (WIFEXITED(status)){
		len =sprintf(buffer,"[exit:%d|%ldms] %% ", WEXITSTATUS(status),elapsed_time);
	} else if (WIFSIGNALED(status)) {
		len =sprintf(buffer,"[sign:%d|%ldms] %% ", WTERMSIG(status),elapsed_time);
	} 
	
	write(1, buffer, len);
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
		
		if (bytesRead == 0){
			//Detection of Ctrl+D
			char end[] = "\n\nBYE BYE AMIGO 🙀 ...";
			int l_end = sizeof(end)-1;
			write(1,end,l_end);
			break;
			
		} else if (bytesRead < 0){
			//Dodge problemen with file's end
			perror("ensea %");
			break;
		}
		
		input[strcspn(input,"\n")]=0;//Erase the new line entry
		
		if (strcmp(input,"exit") == 0){
				char end[] = "\nBYE BYE AMIGO 🙀 ...";
				int l_end = sizeof(end)-1;
				write(1,end,l_end);
			break;
		}
		
		
		
		
		
		long elapsed_time = executeCode(input);
		
		//Display the prompt with the return code of the last command
		int status;
		
		
		
		waitpid(-1,&status,0);
		printPrompt(status,elapsed_time);
		
	}
	return(EXIT_SUCCESS);
}


	

