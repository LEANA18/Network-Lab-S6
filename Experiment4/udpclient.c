#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<string.h>
#include<sys/socket.h>

int main(int argc,char *argv[])
{
	struct sockaddr_in server,client;
	if(argc!=3)
	{
		printf("Input format not correct\n");
	}
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("Error in socket()\n");
	}
	server.sin_family=AF_INET;
	server.sin_port=htons(atoi(argv[2]));
	char buffer[100];
	printf("Enter a message to be sent to the server\n");
	fgets(buffer,100,stdin);
	if(sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*) &server,sizeof(server))<0)
	{
		printf("\nError in sendto: ");
	}
	return 0;
}

	
