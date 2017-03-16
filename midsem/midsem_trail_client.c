#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERV_PORT 8888

int main(int argc, char const *argv[]){

	struct sockaddr_in servaddr,cliaddr;
	int sockfd,clilen;
	FILE *fp;
	char f[100],data[100],output[80];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);

	inet_pton(AF_INET, argv[1] , &servaddr.sin_addr);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	printf("connetion established\n");

	//////////////////////////////////////////

		scanf("%s",data);
		write(sockfd,data,80);

		read(sockfd,output,80);
		printf("the answer is %s\n",output);

	//////////////////////////////////////////

		close(sockfd);

return 0;	
}


 
