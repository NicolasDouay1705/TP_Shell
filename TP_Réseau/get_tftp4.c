#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>



int main(int argc, char* argv[]){
	
	
	// STOCKAGE DES ENTREES: HOST ET FILE
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
	
	// RECUPERATION ADRESSE SERVEUR
	struct addrinfo hints;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_protocol = IPPROTO_UDP;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_family = AF_INET;
	struct addrinfo *res;
	int err;
	err = getaddrinfo(host,"69",&hints,&res);
	if (err != 0){
			printf("%s\n",gai_strerror(err));
			return(EXIT_FAILURE);
	}
	
	
	// CREATION SOCKET
	int server_socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	
    if (server_socket == -1) {
        perror("Erreur lors de la création du socket");
        freeaddrinfo(res);
        return(EXIT_FAILURE);
	}
	else {
		printf("création réussie\n");
	}
	
	/*
	// CONNEXION SERVEUR
	int server_connect = connect(server_socket, res->ai_addr, res->ai_addrlen);
	if (server_connect == -1) {
        perror("Erreur lors de la connexion au serveur");
        close(server_socket);
        freeaddrinfo(res);
        exit(EXIT_FAILURE);
    }
    else {
		printf("Connection résussie\n");
	}
	*/
	    
    //CONSTRUCTION REQUETE RRQ
	int size_RRQ = sizeof(uint16_t)+strlen(file)+1+strlen("octet")+1;
	char *RRQ = (char*) malloc(size_RRQ);
	int Index_RRQ = 0;
	RRQ[Index_RRQ++] = 0;
	RRQ[Index_RRQ++] = 1;
	strcpy(RRQ+Index_RRQ,file);
	Index_RRQ += strlen(file);
	RRQ[Index_RRQ] = '\0';
	strcpy(RRQ+Index_RRQ,"octet");
	Index_RRQ += strlen("octet");
	RRQ[Index_RRQ++] = '\0';
	
	//ENVOIE DU RRQ
	int Envoi_RRQ = sendto(server_socket,RRQ,size_RRQ,0,res->ai_addr,sizeof(server_socket));
	if (Envoi_RRQ == -1){
		perror("Erreur lors de l'envoi du RRQ");
		return(EXIT_FAILURE);
	}
	else {
		printf("Envoie RRQ réussi");
	}
	
	return(EXIT_SUCCESS);
}


