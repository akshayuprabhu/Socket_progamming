#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#define SERV_PORT 5576

int main(int argc,char **argv){

	int i,j;
	ssize_t n;
	FILE *fp;
	char s[80],f[80];
	char chatToClient[100],chatFromClient[100];

	struct sockaddr_in servaddr,cliaddr;

	int listenfd,connfd,clilen;

	listenfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	listen(listenfd,1);

	clilen=sizeof(cliaddr);
	connfd=accept(listenfd,(struct sockaddr*) &cliaddr,&clilen);

	printf("client connected \n");
	
	for(int i=0;i<100;i++){
		read (connfd,chatFromClient,80);
		printf("friend: %s\n",chatFromClient);
		printf("me: ");
		scanf("%s",chatToClient);
		write(connfd,chatToClient,80);
	}

	fclose(fp);



} 
 
