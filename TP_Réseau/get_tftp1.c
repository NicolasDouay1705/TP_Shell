#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char* argv[]){
	
	char* host = (char*) malloc(sizeof(argv[1]));
	char* file = (char*) malloc(sizeof(argv[2]));
	strcpy(host,argv[1]);
	strcpy(file,argv[2]);
	
	/*
	int len_host = sizeof(host)-1;
	write(1,host,len_host);
	printf("\n");
	int len_file = sizeof(file)-1;
	write(1,file,len_file);
	printf("\n");
	*/
	
	return(EXIT_SUCCESS);
}

