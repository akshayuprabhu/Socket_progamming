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

	int option,x;
	char a[80],b[80];
	char op1,op2;

	do{

		puts("choose an opeation\n1.Add\n2.Subtract\n3.Multiplication\n4.division\n5.Square");
		scanf("%d",&option);

		switch(option){

			case 1 :puts("came to 1");
					puts("enter the operands");
					scanf("%s%s",a,b);
					strcat(a," + ");
					strcat(a,b);
					write(sockfd,a,80);
					break;
			case 2 :puts("came to 2");
					puts("enter the operands");
					scanf("%s%s",a,b);
					strcat(a," - ");
					strcat(a,b);
					write(sockfd,a,80);
					break;
			case 3 :puts("came to 3");
					puts("enter the operands");
					scanf("%s%s",a,b);
					strcat(a," * ");
					strcat(a,b);
					write(sockfd,a,80);
					break;
			case 4 :puts("came to 4");
					puts("enter the operands");
					scanf("%s%s",a,b);
					strcat(a," / ");
					strcat(a,b);
					write(sockfd,a,80);
					break;
			case 5 :puts("came to 5");
					puts("enter the operands");
					scanf("%s%s",a,b);
					strcat(a," ^ ");
					strcat(a,b);
					write(sockfd,a,80);
					break;
		}


		read(sockfd,output,80);
		printf("the answer is %s\n",output);

		puts("do you want to continue ?\n 0.NO        1.YES \n");
		scanf("%d",&x);

		// if(x==1)
		// 	write(sockfd,"quit",80);
	}while(x);

		// scanf("%s",data);
		// write(sockfd,data,80);

		// read(sockfd,output,80);
		// printf("the answer is %s\n",output);

	//////////////////////////////////////////

		close(sockfd);

return 0;	
}


 
