//file transfer client program:fileclient.cc

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#define SERV_PORT 5576
int main(int argc,char **argv)
{
int i,j;
ssize_t n;
char filename[80],recvline[80];
char chatFromServer[100],chatToServer[100];
struct sockaddr_in servaddr;
int sockfd;
sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);
inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

printf("Chat started(You can start chatting now):\n");

for(int i=0;i<100;i++){
	printf("me: ");
	scanf("%s",chatToServer);
	write(sockfd,chatToServer,sizeof(chatToServer));
	// scanf("%s",chatT);
	// sleep(2);
	printf("friend: ");
	read(sockfd,chatFromServer,80);
	printf("%s\n",chatFromServer);
	// fputs(chatFromServer,stdout);
}


close(sockfd);

return 0;
}

