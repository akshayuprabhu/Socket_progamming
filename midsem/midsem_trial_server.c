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
	int connfd,listenfd,clilen;
	FILE *fp;
	char f[100],output[100],echo[80]="echo ";

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);

	bind(listenfd, (struct sockaddr *)&servaddr,sizeof(servaddr));

	listen(listenfd,1);

	clilen = sizeof(cliaddr);

	connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);

	printf("connetion established\n");

	////////////////////////////////////

	while( read(connfd,f,80) !=NULL ){

		strcat(echo,f);
		strcat(echo, " | bc  > fileoutput ");

		system(echo);

		fp=fopen("fileoutput","r");

		while( (fgets(output,sizeof(output),fp))!=NULL ){
			printf("the answer is %s \n",output );
			write(connfd,output,80);
		}

		fclose(fp);
	}

	close(connfd);

	////////////////////////////////////

return 0;	
}


