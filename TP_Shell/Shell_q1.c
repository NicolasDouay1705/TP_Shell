#include <unistd.h>
#include <stdlib.h>

int main(int argc,char* argv){
	char entete[] = "$ ./enseash \nBienvenue dans le SHELL ENSEA \nPour quitter, tapez 'exit'! \n enseash %";
	int length = sizeof(entete)-1;
	write(1,entete,length);

	return(EXIT_SUCCESS);
}

